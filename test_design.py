import logging
import numpy
from bitstring import BitArray
from PIL import Image

from SN74LS00 import SN74LS00
from SN74LS20 import SN74LS20
from SN74LS04 import SN74LS04
from SN74LS30 import SN74LS30
from SN74LS161A import SN74LS161A
from constant_value import ConstantValue
from clock import Clock

logging.basicConfig(level=logging.INFO)
log = logging.getLogger("TestDesign")

SUBCLOCKS = 2

VCC = ConstantValue("VCC", True)
GND = ConstantValue("GND", False)

CLK = Clock()

nodes = []

# Horizontal counters
ha = SN74LS161A("HA")
hb = SN74LS161A("HB")
hc = SN74LS161A("HC")
nodes.append(ha)
nodes.append(hb)
nodes.append(hc)

# Connect counter to clock and chain the count overflow
ha.connect_node(CLK, 'A', 'CP')
hb.connect_node(ha, 'TC', 'CP')
hc.connect_node(hb, 'TC', 'CP')

invert = SN74LS04("Invert")
nodes.append(invert)
invert.connect_node(GND, 'A', ['1A', '2A', '3A', '4A', '5A'])
invert.connect_node(hb, 'Q1', '6A')

# Count 262 detection
h262_h300 = SN74LS20("H262_H300")
nodes.append(h262_h300)
h262_h300.connect_node(hc, 'Q0', 'A1')
h262_h300.connect_node(ha, 'Q1', 'B1')
h262_h300.connect_node(ha, 'Q2', 'C1')
h262_h300.connect_node(invert, '6Y', 'D1')

# Count 300 detection
h262_h300.connect_node(hc, 'Q0', 'A2')
h262_h300.connect_node(ha, 'Q2', 'B2')
h262_h300.connect_node(hb, 'Q1', 'C2')
h262_h300.connect_node(ha, 'Q3', 'D2')

# Count 318 detection
h318 = SN74LS30("H318")
nodes.append(h318)
h318.connect_node(hc, 'Q0', 'A')
h318.connect_node(ha, 'Q1', 'B')
h318.connect_node(ha, 'Q2', 'C')
h318.connect_node(ha, 'Q3', 'D')
h318.connect_node(hb, 'Q0', 'E')
h318.connect_node(hb, 'Q1', 'F')
h318.connect_node(VCC, 'A', ['G', 'H'])

# Connect count 318 to horizontal count reset
ha.connect_node(h318, 'Y', 'MR')
hb.connect_node(h318, 'Y', 'MR')
hc.connect_node(h318, 'Y', 'MR')

h_sr_latch = SN74LS00("HSrLatch")
nodes.append(h_sr_latch)
# Hsync detection on 3Y
h_sr_latch.connect_node(h262_h300, 'Y2', '3B')
h_sr_latch.connect_node(h_sr_latch, '4Y', '3A')
h_sr_latch.connect_node(h_sr_latch, '3Y', '4B')
h_sr_latch.connect_node(h262_h300, 'Y1', '4A')
# HBlank detection on 1Y
h_sr_latch.connect_node(hc, 'Q0', '1A')
h_sr_latch.connect_node(hc, 'Q0', '1B')

h_sr_latch.connect_node(GND, 'A', ['2A', '2B'])

# Vertical counters
va = SN74LS161A("VA")
vb = SN74LS161A("VB")
vc = SN74LS161A("Vc")
nodes.append(va)
nodes.append(vb)
nodes.append(vc)

# Connect counter to horizontal counters
va.connect_node(h_sr_latch, '4Y', 'CP')
vb.connect_node(va, 'TC', 'CP')
vc.connect_node(vb, 'TC', 'CP')

va.connect_node(VCC, 'A', 'MR')
vb.connect_node(VCC, 'A', 'MR')
vc.connect_node(VCC, 'A', 'MR')

v480_v525 = SN74LS20("V480_V525")
nodes.append(v480_v525)
v480_v525.connect_node(vc, 'Q0', 'A1')
v480_v525.connect_node(vb, 'Q1', 'B1')
v480_v525.connect_node(vb, 'Q2', 'C1')
v480_v525.connect_node(vb, 'Q3', 'D1')

v480_v525.connect_node(va, 'Q0', 'A2')
v480_v525.connect_node(vc, 'Q1', 'B2')
v480_v525.connect_node(va, 'Q2', 'C2')
v480_v525.connect_node(va, 'Q3', 'D2')

invert.connect_node(va, 'Q2', '1A')
invert.connect_node(vb, 'Q0', '2A')

h_sr_latch.connect_node(invert, '1Y', '2A')
h_sr_latch.connect_node(invert, '2Y', '2B')

invert.connect_node(h_sr_latch, '2Y', '3A')

v490 = SN74LS30("V490")
nodes.append(v490)
v490.connect_node(invert, '3Y', 'A')
v490.connect_node(va, 'Q1', 'B')
v490.connect_node(va, 'Q3', 'C')
v490.connect_node(vb, 'Q1', 'D')
v490.connect_node(vb, 'Q2', 'E')
v490.connect_node(vb, 'Q3', 'F')
v490.connect_node(vc, 'Q0', 'G')
v490.connect_node(VCC, 'A', 'H')

v492 = SN74LS30("V492")
nodes.append(v492)
v492.connect_node(va, 'Q2', 'A')
v492.connect_node(va, 'Q3', 'B')
v492.connect_node(vb, 'Q1', 'C')
v492.connect_node(vb, 'Q2', 'D')
v492.connect_node(vb, 'Q3', 'E')
v492.connect_node(vc, 'Q0', 'F')
v492.connect_node(VCC, 'A', ['G', 'H'])

v_sr_latch = SN74LS00("VSrLatch")
nodes.append(v_sr_latch)
# Vsync detection on 2Y
v_sr_latch.connect_node(v_sr_latch, '2Y', '1A')
v_sr_latch.connect_node(v480_v525, 'Y2', '1B')
v_sr_latch.connect_node(v_sr_latch, '1Y', '2A')
v_sr_latch.connect_node(v480_v525, 'Y1', '2B')

v_sr_latch.connect_node(v_sr_latch, '4Y', '3A')
v_sr_latch.connect_node(v492, 'Y', '3B')
v_sr_latch.connect_node(v_sr_latch, '3Y', '4B')
v_sr_latch.connect_node(v490, 'Y', '4A')

framebuffer = numpy.zeros(shape=(525,318), dtype=numpy.uint8)
subclock = 0
while CLK.count < 166950:
    if subclock < SUBCLOCKS:
        subclock += 1
    else:
        CLK.clock()
        subclock = 0

    for node in nodes:
        node.cook()

    if subclock == 0:
        print(CLK.count)
        x = BitArray(bin="{}{}{}".format(hc, hb, ha)).uint
        y = BitArray(bin="{}{}{}".format(vc, vb, va)).uint
        if x < 318 and y < 525:
            h_sync = h_sr_latch.output_value('3Y') * 63
            h_blank = h_sr_latch.output_value('1Y') * 63
            v_sync = v_sr_latch.output_value('3Y') * 63
            v_blank = v_sr_latch.output_value('1Y') * 63
            framebuffer[y][x] = h_sync + h_blank + v_blank + v_sync
    #print("Count : {} - {} - {}".format(hc, hb, ha))
    
    #h_sync = h_sr_latch.output_value('3Y')
    #if (not h_sync and subclock == 0):
    #    log.info("HSYNC")

    #h_blank = h_sr_latch.output_value('1Y')
    #if (not h_blank and subclock == 0):
    #    log.info("HBlank")

    #    if latch:
    #        log.info(CLK)
    #        print("Count : {} - {} - {}".format(vc, vb, va))

img = Image.fromarray(framebuffer, mode='L')
img.show()