#include "chips/constant_value.h"
#include "chips/clock.h"
#include "chips/SN74LS00.h"
#include "chips/SN74LS04.h"
#include "chips/SN74LS20.h"
#include "chips/SN74LS30.h"
#include "chips/SN74LS161A.h"

#include <iostream>
#include <cstdio>
#include <bitset>
#include <string>

using namespace IcSim;

int main(int argc, char **argv)
{
    // Clock
    Clock CLK;

    // Constants
    ConstantValue VCC("VCC", 1);
    ConstantValue GND("GND", 0);
    
    // Horizontal counters
    SN74LS161A ha("HA");
    SN74LS161A hb("HB");
    SN74LS161A hc("HC");
    ha.connect_input(&VCC, "A", {"PE", "CET", "CEP"});
    ha.connect_input(&GND, "A", {"P0", "P1", "P2", "P3"});
    hb.connect_input(&VCC, "A", InputVector{"PE", "CEP"});
    hb.connect_input(&GND, "A", {"P0", "P1", "P2", "P3"});
    hc.connect_input(&VCC, "A", InputVector{"PE", "CEP"});
    hc.connect_input(&GND, "A", {"P0", "P1", "P2", "P3"});

    // Connect counter to clock and chain the count overflow
    ha.connect_input(&CLK, "A", "CP");
    hb.connect_input(&CLK, "A", "CP");
    hc.connect_input(&CLK, "A", "CP");
    hb.connect_input(&ha, "TC", "CET");
    hc.connect_input(&hb, "TC", "CET");

    SN74LS04 invert("Invert");
    invert.connect_input(&hb, "Q1", "6A");

    // Count 262 detection
    SN74LS20 h262_h300("H262_H300");
    h262_h300.connect_input(&hc, "Q0", "A1");
    h262_h300.connect_input(&ha, "Q1", "B1");
    h262_h300.connect_input(&ha, "Q2", "C1");
    h262_h300.connect_input(&invert, "6Y", "D1");

    // Count 300 detection
    h262_h300.connect_input(&hc, "Q0", "A2");
    h262_h300.connect_input(&ha, "Q2", "B2");
    h262_h300.connect_input(&hb, "Q1", "C2");
    h262_h300.connect_input(&ha, "Q3", "D2");

    // Count 318 detection
    SN74LS30 h318("H318");
    h318.connect_input(&hc, "Q0", "A");
    h318.connect_input(&ha, "Q1", "B");
    h318.connect_input(&ha, "Q2", "C");
    h318.connect_input(&ha, "Q3", "D");
    h318.connect_input(&hb, "Q0", "E");
    h318.connect_input(&hb, "Q1", "F");
    h318.connect_input(&VCC, "A", InputVector{"G", "H"});

    // Connect count 318 to horizontal count reset
    ha.connect_input(&h318, "Y", "MR");
    hb.connect_input(&h318, "Y", "MR");
    hc.connect_input(&h318, "Y", "MR");

    SN74LS00 h_sr_latch("HSrLatch");
    // Hsync detection on 3Y
    h_sr_latch.connect_input(&h262_h300, "Y2", "3B");
    h_sr_latch.connect_input(&h_sr_latch, "3Y", "4B");
    h_sr_latch.connect_input(&h_sr_latch, "4Y", "3A");
    h_sr_latch.connect_input(&h262_h300, "Y1", "4A");
    // HBlank detection on 1Y
    h_sr_latch.connect_input(&hc, "Q0", "1A");
    h_sr_latch.connect_input(&hc, "Q0", "1B");

    invert.connect_input(&ha, "Q0", "4A");
    invert.connect_input(&hb, "Q0", "5A");

    SN74LS30 hstart("HStart");
    hstart.connect_input(&ha, "Q1", "A");
    hstart.connect_input(&ha, "Q2", "B");
    hstart.connect_input(&ha, "Q3", "C");
    hstart.connect_input(&invert, "4Y", "D");
    hstart.connect_input(&invert, "5Y", "E");
    hstart.connect_input(&hb, "Q1", "F");
    hstart.connect_input(&hc, "Q0", "G");
    hstart.connect_input(&VCC, "A", "H");

    // Vertical counters
    SN74LS161A va("VA");
    SN74LS161A vb("VB");
    SN74LS161A vc("VC");
    va.connect_input(&VCC, "A", {"PE", "CET", "CEP"});
    va.connect_input(&GND, "A", {"P0", "P1", "P2", "P3"});
    vb.connect_input(&VCC, "A", InputVector{"PE", "CEP"});
    vb.connect_input(&GND, "A", {"P0", "P1", "P2", "P3"});
    vc.connect_input(&VCC, "A", InputVector{"PE", "CEP"});
    vc.connect_input(&GND, "A", {"P0", "P1", "P2", "P3"});

    // Connect counter to vertical counters
    va.connect_input(&h_sr_latch, "4Y", "CP");
    vb.connect_input(&h_sr_latch, "4Y", "CP");
    vc.connect_input(&h_sr_latch, "4Y", "CP");
    vb.connect_input(&va, "TC", "CET");
    vc.connect_input(&vb, "TC", "CET");

    SN74LS20 v480_v525("V480_V525");
    v480_v525.connect_input(&vc, "Q0", "A1");
    v480_v525.connect_input(&vb, "Q1", "B1");
    v480_v525.connect_input(&vb, "Q2", "C1");
    v480_v525.connect_input(&vb, "Q3", "D1");

    v480_v525.connect_input(&va, "Q0", "A2");
    v480_v525.connect_input(&vc, "Q1", "B2");
    v480_v525.connect_input(&va, "Q2", "C2");
    v480_v525.connect_input(&va, "Q3", "D2");

    invert.connect_input(&va, "Q2", "1A");
    invert.connect_input(&vb, "Q0", "2A");

    h_sr_latch.connect_input(&invert, "1Y", "2A");
    h_sr_latch.connect_input(&invert, "2Y", "2B");

    invert.connect_input(&h_sr_latch, "2Y", "3A");

    SN74LS30 v490("V490");
    v490.connect_input(&invert, "3Y", "A");
    v490.connect_input(&va, "Q1", "B");
    v490.connect_input(&va, "Q3", "C");
    v490.connect_input(&vb, "Q1", "D");
    v490.connect_input(&vb, "Q2", "E");
    v490.connect_input(&vb, "Q3", "F");
    v490.connect_input(&vc, "Q0", "G");
    v490.connect_input(&VCC, "A", "H");

    SN74LS30 v492("V492");
    v492.connect_input(&va, "Q2", "A");
    v492.connect_input(&va, "Q3", "B");
    v492.connect_input(&vb, "Q1", "C");
    v492.connect_input(&vb, "Q2", "D");
    v492.connect_input(&vb, "Q3", "E");
    v492.connect_input(&vc, "Q0", "F");
    v492.connect_input(&VCC, "A", InputVector{"G", "H"});

    va.connect_input(&v480_v525, "Y2", "MR");
    vb.connect_input(&v480_v525, "Y2", "MR");
    vc.connect_input(&v480_v525, "Y2", "MR");

    SN74LS00 v_sr_latch("VSrLatch");
    // Vsync detection on 3Y
    v_sr_latch.connect_input(&v480_v525, "Y2", "1A");
    v_sr_latch.connect_input(&v_sr_latch, "2Y", "1B");
    v_sr_latch.connect_input(&v_sr_latch, "1Y", "2A");
    v_sr_latch.connect_input(&v480_v525, "Y1", "2B");
    // Vblank detection on 1Y
    v_sr_latch.connect_input(&v_sr_latch, "4Y", "3A");
    v_sr_latch.connect_input(&v492, "Y", "3B");
    v_sr_latch.connect_input(&v_sr_latch, "3Y", "4B");
    v_sr_latch.connect_input(&v490, "Y", "4A");

    // Open output image
    std::freopen("output.ppm", "w", stdout);
    std::cout << "P3\n" << 318 << " " << 525 << "\n255\n";

    int end_count = 166950*2;
    while (CLK.count < end_count)
    {
        // Start propagation from the clock
        bool propagate = false;
        CLK.cook(propagate);
        if (propagate) {
            CLK.propagate();
        }

        if (CLK.count > 166950 && CLK.output_value("A")) {
            //std::cerr << h_sr_latch.output_value("4Y") << std::endl;
            int h_sync = h_sr_latch.output_value("3Y")*255;
            int h_blank = h_sr_latch.output_value("1Y")*255;
            int v_sync = v_sr_latch.output_value("3Y")*255;
            int v_blank = v_sr_latch.output_value("1Y")*255;
            std::bitset<12> count;
            count[0]  = va.output_value("Q0");
            count[1]  = va.output_value("Q1");
            count[2]  = va.output_value("Q2");
            count[3]  = va.output_value("Q3");
            count[4]  = vb.output_value("Q0");
            count[5]  = vb.output_value("Q1");
            count[6]  = vb.output_value("Q2");
            count[7]  = vb.output_value("Q3");
            count[8]  = vc.output_value("Q0");
            count[9]  = vc.output_value("Q1");
            count[10] = vc.output_value("Q2");
            count[11] = vc.output_value("Q3");
            // double alpha = count.to_ullong()/525.0;
            // int value = int(255*alpha);
            ///std::cerr << vc << vb << va << std::endl;
            //std::cerr << count.to_ullong() << std::endl;
            std::cout << v_sync << " " << v_blank << " " << 0 << "\n";
        }

        // Log the progress
        if (CLK.should_log()) {
            std::cerr << "Percent : " << int((double(CLK.count)/double(end_count))*100.0) << "%" << std::endl;
        }
    }

    std::cerr << "Done" << std::endl;

    return 1;
}