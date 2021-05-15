#include "chips/constant_value.h"
#include "chips/clock.h"
#include "chips/SN74LS00.h"
#include "chips/SN74LS04.h"
#include "chips/SN74LS08.h"
#include "chips/SN74LS20.h"
#include "chips/SN74LS30.h"
#include "chips/SN74LS161A.h"
#include "chips/SN74HC163N.h"
#include "chips/SN74HC373.h"

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
    hb.connect_input(&VCC, "A", InputStringVector{"PE", "CEP"});
    hb.connect_input(&GND, "A", {"P0", "P1", "P2", "P3"});
    hc.connect_input(&VCC, "A", InputStringVector{"PE", "CEP"});
    hc.connect_input(&GND, "A", {"P0", "P1", "P2", "P3"});

    // Connect counter to clock and chain the count overflow
    ha.connect_input(&CLK, "A", "CP");
    hb.connect_input(&CLK, "A", "CP");
    hc.connect_input(&CLK, "A", "CP");
    hb.connect_input(&ha, "TC", "CET");
    hc.connect_input(&hb, "TC", "CET");

    SN74LS04 count_invert("CountInvert");
    count_invert.connect_input(&hb, "Q1", "6A");

    // Count 262 detection
    SN74LS20 h262_h300("H262_H300");
    h262_h300.connect_input(&hc, "Q0", "A1");
    h262_h300.connect_input(&ha, "Q1", "B1");
    h262_h300.connect_input(&ha, "Q2", "C1");
    h262_h300.connect_input(&count_invert, "6Y", "D1");

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
    h318.connect_input(&VCC, "A", InputStringVector{"G", "H"});

    // Connect count 318 to horizontal count reset
    ha.connect_input(&h318, "Y", "MR");
    hb.connect_input(&h318, "Y", "MR");
    hc.connect_input(&h318, "Y", "MR");

    SN74LS00 h_sr_latch("HSrLatch");
    // Hsync detection on 3Y, HsyncB detection on 4Y
    h_sr_latch.connect_input(&h262_h300, "Y2", "3B");
    h_sr_latch.connect_input(&h_sr_latch, "3Y", "4B");
    h_sr_latch.connect_input(&h_sr_latch, "4Y", "3A");
    h_sr_latch.connect_input(&h262_h300, "Y1", "4A");
    // HBlank detection on 1Y
    h_sr_latch.connect_input(&hc, "Q0", "1A");
    h_sr_latch.connect_input(&hc, "Q0", "1B");

    count_invert.connect_input(&ha, "Q0", "4A");
    count_invert.connect_input(&hb, "Q0", "5A");

    SN74LS30 hstart("HStart");
    hstart.connect_input(&ha, "Q1", "A");
    hstart.connect_input(&ha, "Q2", "B");
    hstart.connect_input(&ha, "Q3", "C");
    hstart.connect_input(&count_invert, "4Y", "D");
    hstart.connect_input(&count_invert, "5Y", "E");
    hstart.connect_input(&hb, "Q1", "F");
    hstart.connect_input(&hc, "Q0", "G");
    hstart.connect_input(&VCC, "A", "H");

    // Vertical counters
    SN74LS161A va("VA");
    SN74LS161A vb("VB");
    SN74LS161A vc("VC");
    va.connect_input(&VCC, "A", {"PE", "CET", "CEP"});
    va.connect_input(&GND, "A", {"P0", "P1", "P2", "P3"});
    vb.connect_input(&VCC, "A", InputStringVector{"PE", "CEP"});
    vb.connect_input(&GND, "A", {"P0", "P1", "P2", "P3"});
    vc.connect_input(&VCC, "A", InputStringVector{"PE", "CEP"});
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

    count_invert.connect_input(&va, "Q2", "1A");
    count_invert.connect_input(&vb, "Q0", "2A");

    h_sr_latch.connect_input(&count_invert, "1Y", "2A");
    h_sr_latch.connect_input(&count_invert, "2Y", "2B");

    count_invert.connect_input(&h_sr_latch, "2Y", "3A");

    SN74LS30 v490("V490");
    v490.connect_input(&count_invert, "3Y", "A");
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
    v492.connect_input(&VCC, "A", InputStringVector{"G", "H"});

    va.connect_input(&v480_v525, "Y2", "MR");
    vb.connect_input(&v480_v525, "Y2", "MR");
    vc.connect_input(&v480_v525, "Y2", "MR");

    SN74LS00 v_sr_latch("VSrLatch");
    // Vsync detection on 3Y, VsyncB detection on 4Y
    v_sr_latch.connect_input(&v492, "Y", "3B");
    v_sr_latch.connect_input(&v_sr_latch, "4Y", "3A");
    v_sr_latch.connect_input(&v_sr_latch, "3Y", "4B");
    v_sr_latch.connect_input(&v490, "Y", "4A");
    // Vblank detection on 1Y, VblankB detection on 2Y
    v_sr_latch.connect_input(&v480_v525, "Y2", "1A");
    v_sr_latch.connect_input(&v_sr_latch, "2Y", "1B");
    v_sr_latch.connect_input(&v_sr_latch, "1Y", "2A");
    v_sr_latch.connect_input(&v480_v525, "Y1", "2B");

    // PPU Control
    SN74HC373 ppu_control("PPUControl");
    ppu_control.connect_input(&VCC, "A", "LE");
    ppu_control.connect_input(&GND, "A", {"OE", "D2", "D3", "D4", "D5", "D6", "D7"});
    ppu_control.connect_input(&GND, "A", InputStringVector{"D0", "D1"});

    // BG Count H
    SN74HC163N bgha("BGHCount1");
    SN74HC163N bghb("BGHCount2");
    bgha.connect_input(&CLK, "A", "CP");
    bgha.connect_input(&VCC, "A", {"MR", "CEP", "CET"});
    bgha.connect_input(&hstart, "Y", "PE");
    bgha.connect_input(&GND, "A", {"D0", "D1", "D2"});
    bghb.connect_input(&CLK, "A", "CP");
    bghb.connect_input(&VCC, "A", InputStringVector{"MR", "CEP"});
    bghb.connect_input(&bgha, "TC", "CET");
    bghb.connect_input(&hstart, "Y", "PE");

    SN74HC373 bgh_offset("BGHOffsetLatch");
    bgh_offset.connect_input(&VCC, "A", "LE");
    bgh_offset.connect_input(&GND, "A", {"OE", "D0", "D1", "D2", "D3", "D4", "D5", "D6"});
    bgh_offset.connect_input(&VCC, "A", "D7");

    bgha.connect_input(&bgh_offset, "Q3", "D3");
    bghb.connect_input(&bgh_offset, "Q4", "D0");
    bghb.connect_input(&bgh_offset, "Q5", "D1");
    bghb.connect_input(&bgh_offset, "Q6", "D2");
    bghb.connect_input(&bgh_offset, "Q7", "D3");

    // BG Count V
    SN74HC163N bgva("BGVCount1");
    SN74HC163N bgvb("BGVCount2");
    bgva.connect_input(&va, "Q0", "CP");
    bgva.connect_input(&VCC, "A", InputStringVector{"CEP", "CET"});
    bgva.connect_input(&v_sr_latch, "1Y", "PE");
    bgva.connect_input(&GND, "A", {"D0", "D1", "D2"});
    bgvb.connect_input(&va, "Q0", "CP");
    bgvb.connect_input(&VCC, "A", "CEP");
    bgvb.connect_input(&bgva, "TC", "CET");
    bgvb.connect_input(&v_sr_latch, "1Y", "PE");

    SN74HC373 bgv_offset("BGVOffsetLatch");
    bgv_offset.connect_input(&VCC, "A", "LE");
    bgv_offset.connect_input(&GND, "A", {"OE", "D0", "D1", "D2", "D3", "D4", "D5", "D6"});
    bgv_offset.connect_input(&VCC, "A", "D7");

    bgva.connect_input(&bgv_offset, "Q0", "D0");
    bgva.connect_input(&bgv_offset, "Q1", "D1");
    bgva.connect_input(&bgv_offset, "Q2", "D2");
    bgva.connect_input(&bgv_offset, "Q3", "D3");
    bgvb.connect_input(&bgv_offset, "Q4", "D0");
    bgvb.connect_input(&bgv_offset, "Q5", "D1");
    bgvb.connect_input(&bgv_offset, "Q6", "D2");
    bgvb.connect_input(&bgv_offset, "Q7", "D3");

    SN74LS30 bgv_reset("BGVReset");
    bgv_reset.connect_input(&bgvb, "Q0", "A");
    bgv_reset.connect_input(&bgvb, "Q1", "B");
    bgv_reset.connect_input(&bgvb, "Q2", "C");
    bgv_reset.connect_input(&bgvb, "Q3", "D");
    bgv_reset.connect_input(&VCC, "A", {"E", "F", "G", "H"});

    bgva.connect_input(&bgv_reset, "Y", "MR");
    bgvb.connect_input(&bgv_reset, "Y", "MR");

    SN74LS04 bg_invert("BgInvert");
    bg_invert.connect_input(&bghb, "TC", "6A");
    bg_invert.connect_input(&GND, "A", {"1A", "2A", "3A", "4A", "5A"});

    SN74LS00 bg_sr_latch("BgSrLatch");
    bg_sr_latch.connect_input(&h_sr_latch, "3Y", "1A");
    bg_sr_latch.connect_input(&bg_sr_latch, "2Y", "1B");
    bg_sr_latch.connect_input(&bg_sr_latch, "1Y", "2A");
    bg_sr_latch.connect_input(&bg_invert, "6Y", "2B");

    bg_sr_latch.connect_input(&v_sr_latch, "3Y", "3B");
    bg_sr_latch.connect_input(&bg_sr_latch, "4Y", "3A");
    bg_sr_latch.connect_input(&bg_sr_latch, "3Y", "4B");
    bg_sr_latch.connect_input(&bgv_reset, "Y", "4A");

    SN74LS08 bg_and("BgAND");
    bg_and.connect_input(&GND, "A", {"A3", "B3", "A4", "B4"});
    bg_and.connect_input(&bg_sr_latch, "2Y", "A1");
    bg_and.connect_input(&ppu_control, "Q0", "B1");
    bg_and.connect_input(&bg_sr_latch, "4Y", "A2");
    bg_and.connect_input(&ppu_control, "Q1", "B2");

    // Make sure all nodes that connect to VCC and Ground but not CLK
    // are cooked at least once first to set up any internal state
    VCC.propagate();
    GND.propagate();

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
            int h_nametable = bg_and.output_value("Y1")*255;
            int v_nametable = bg_and.output_value("Y2")*255;
            std::bitset<8> h_count;
            std::bitset<8> v_count;
            // count[0]  = va.output_value("Q0");
            // count[1]  = va.output_value("Q1");
            // count[2]  = va.output_value("Q2");
            // count[3]  = va.output_value("Q3");
            // count[4]  = vb.output_value("Q0");
            // count[5]  = vb.output_value("Q1");
            // count[6]  = vb.output_value("Q2");
            // count[7]  = vb.output_value("Q3");
            // count[8]  = vc.output_value("Q0");
            // count[9]  = vc.output_value("Q1");
            // count[10] = vc.output_value("Q2");
            // count[11] = vc.output_value("Q3");

            h_count[0]  = bgha.output_value("Q0");
            h_count[1]  = bgha.output_value("Q1");
            h_count[2]  = bgha.output_value("Q2");
            h_count[3]  = bgha.output_value("Q3");
            h_count[4]  = bghb.output_value("Q0");
            h_count[5]  = bghb.output_value("Q1");
            h_count[6]  = bghb.output_value("Q2");
            h_count[7]  = bghb.output_value("Q3");
            double h_alpha = h_count.to_ullong()/318.0;
            int h_value = int(255*h_alpha);

            v_count[0]  = bgva.output_value("Q0");
            v_count[1]  = bgva.output_value("Q1");
            v_count[2]  = bgva.output_value("Q2");
            v_count[3]  = bgva.output_value("Q3");
            v_count[4]  = bgvb.output_value("Q0");
            v_count[5]  = bgvb.output_value("Q1");
            v_count[6]  = bgvb.output_value("Q2");
            v_count[7]  = bgvb.output_value("Q3");
            double v_alpha = v_count.to_ullong()/525.0;
            int v_value = int(255*v_alpha);
            std::cout << v_value << " " << v_nametable << " " << 0 << "\n";
        }

        // Log the progress
        if (CLK.should_log()) {
            std::cerr << "Percent : " << int((double(CLK.count)/double(end_count))*100.0) << "%" << std::endl;
        }
    }

    std::cerr << "Done" << std::endl;

    return 1;
}