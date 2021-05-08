import logging
import numpy
from bitstring import BitArray
from PIL import Image

from circuit_factory import CircuitFactory

logging.basicConfig(level=logging.DEBUG)
log = logging.getLogger("TestDesign")

circuit = CircuitFactory()

# Horizontal counters
ha = circuit.create_ic('HA', 'SN74LS161A')
hb = circuit.create_ic('HB', 'SN74LS161A')
hc = circuit.create_ic('HC', 'SN74LS161A')
ha.connect_node(circuit.VCC, 'A', ['PE', 'CET', 'CEP'])
ha.connect_node(circuit.GND, 'A', ['P0', 'P1', 'P2', 'P3'])
hb.connect_node(circuit.VCC, 'A', ['PE', 'CEP'])
hb.connect_node(circuit.GND, 'A', ['P0', 'P1', 'P2', 'P3'])
hc.connect_node(circuit.VCC, 'A', ['PE', 'CEP'])
hc.connect_node(circuit.GND, 'A', ['P0', 'P1', 'P2', 'P3'])

# Connect counter to clock and chain the count overflow
ha.connect_node(circuit.CLK, 'A', 'CP')
hb.connect_node(circuit.CLK, 'A', 'CP')
hc.connect_node(circuit.CLK, 'A', 'CP')
hb.connect_node(ha, 'TC', 'CET')
hc.connect_node(hb, 'TC', 'CET')

invert = circuit.create_ic('Invert', 'SN74LS04')
invert.connect_node(hb, 'Q1', '6A')

# Count 262 detection
h262_h300 = circuit.create_ic('H262_H300', 'SN74LS20')
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
h318 = circuit.create_ic('H318', 'SN74LS30')
h318.connect_node(hc, 'Q0', 'A')
h318.connect_node(ha, 'Q1', 'B')
h318.connect_node(ha, 'Q2', 'C')
h318.connect_node(ha, 'Q3', 'D')
h318.connect_node(hb, 'Q0', 'E')
h318.connect_node(hb, 'Q1', 'F')
h318.connect_node(circuit.VCC, 'A', ['G', 'H'])

# Connect count 318 to horizontal count reset
ha.connect_node(h318, 'Y', 'MR')
hb.connect_node(h318, 'Y', 'MR')
hc.connect_node(h318, 'Y', 'MR')

h_sr_latch = circuit.create_ic('HSrLatch', 'SN74LS00')
# Hsync detection on 3Y
h_sr_latch.connect_node(h262_h300, 'Y2', '3B')
h_sr_latch.connect_node(h_sr_latch, '3Y', '4B')
h_sr_latch.connect_node(h_sr_latch, '4Y', '3A')
h_sr_latch.connect_node(h262_h300, 'Y1', '4A')
# HBlank detection on 1Y
h_sr_latch.connect_node(hc, 'Q0', '1A')
h_sr_latch.connect_node(hc, 'Q0', '1B')

invert.connect_node(ha, 'Q0', '4A')
invert.connect_node(hb, 'Q0', '5A')

hstart = circuit.create_ic('HStart', 'SN74LS30')
hstart.connect_node(ha, 'Q1', 'A')
hstart.connect_node(ha, 'Q2', 'B')
hstart.connect_node(ha, 'Q3', 'C')
hstart.connect_node(invert, '4Y', 'D')
hstart.connect_node(invert, '5Y', 'E')
hstart.connect_node(hb, 'Q1', 'F')
hstart.connect_node(hc, 'Q0', 'G')
hstart.connect_node(circuit.VCC, 'A', 'H')

# Vertical counters
va = circuit.create_ic('VA', 'SN74LS161A')
vb = circuit.create_ic('VB', 'SN74LS161A')
vc = circuit.create_ic('VC', 'SN74LS161A')
va.connect_node(circuit.VCC, 'A', ['PE', 'CET', 'CEP'])
va.connect_node(circuit.GND, 'A', ['P0', 'P1', 'P2', 'P3'])
vb.connect_node(circuit.VCC, 'A', ['PE', 'CEP'])
vb.connect_node(circuit.GND, 'A', ['P0', 'P1', 'P2', 'P3'])
vc.connect_node(circuit.VCC, 'A', ['PE', 'CEP'])
vc.connect_node(circuit.GND, 'A', ['P0', 'P1', 'P2', 'P3'])

# Connect counter to vertical counters
va.connect_node(h_sr_latch, '4Y', 'CP')
vb.connect_node(h_sr_latch, '4Y', 'CP')
vc.connect_node(h_sr_latch, '4Y', 'CP')
vb.connect_node(va, 'TC', 'CET')
vc.connect_node(vb, 'TC', 'CET')

v480_v525 = circuit.create_ic('V480_V525', 'SN74LS20')
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

v490 = circuit.create_ic('V490', 'SN74LS30')
v490.connect_node(invert, '3Y', 'A')
v490.connect_node(va, 'Q1', 'B')
v490.connect_node(va, 'Q3', 'C')
v490.connect_node(vb, 'Q1', 'D')
v490.connect_node(vb, 'Q2', 'E')
v490.connect_node(vb, 'Q3', 'F')
v490.connect_node(vc, 'Q0', 'G')
v490.connect_node(circuit.VCC, 'A', 'H')

v492 = circuit.create_ic('V492', 'SN74LS30')
v492.connect_node(va, 'Q2', 'A')
v492.connect_node(va, 'Q3', 'B')
v492.connect_node(vb, 'Q1', 'C')
v492.connect_node(vb, 'Q2', 'D')
v492.connect_node(vb, 'Q3', 'E')
v492.connect_node(vc, 'Q0', 'F')
v492.connect_node(circuit.VCC, 'A', ['G', 'H'])

va.connect_node(v480_v525, 'Y2', 'MR')
vb.connect_node(v480_v525, 'Y2', 'MR')
vc.connect_node(v480_v525, 'Y2', 'MR')

v_sr_latch = circuit.create_ic('VSrLatch', 'SN74LS00')
# Vsync detection on 2Y
v_sr_latch.connect_node(v480_v525, 'Y2', '1A')
v_sr_latch.connect_node(v_sr_latch, '2Y', '1B')
v_sr_latch.connect_node(v_sr_latch, '1Y', '2A')
v_sr_latch.connect_node(v480_v525, 'Y1', '2B')

v_sr_latch.connect_node(v_sr_latch, '4Y', '3A')
v_sr_latch.connect_node(v492, 'Y', '3B')
v_sr_latch.connect_node(v_sr_latch, '3Y', '4B')
v_sr_latch.connect_node(v490, 'Y', '4A')

# BG Count H
bgha = circuit.create_ic('BGHCountA', 'SN74HC163N')
bgha.connect_node(circuit.CLK, 'A', 'CP')
bgha.connect_node(circuit.VCC, 'A', ['MR', 'CEP', 'CET'])
bgha.connect_node(hstart, 'Y', 'PE')
bgha.connect_node(circuit.GND, 'A', 'D0')
bgha.connect_node(circuit.GND, 'A', 'D1')
bgha.connect_node(circuit.GND, 'A', 'D2')

bghb = circuit.create_ic('BGHCountB', 'SN74HC163N')
bghb.connect_node(circuit.CLK, 'A', 'CP')
bghb.connect_node(circuit.VCC, 'A', ['MR', 'CEP'])
bghb.connect_node(bgha, 'TC', 'CET')
bghb.connect_node(hstart, 'Y', 'PE')

bgh_offset = circuit.create_ic('BGHOffsetLatch', 'SN74HC373')
bgh_offset.connect_node(circuit.VCC, 'A', 'LE')
bgh_offset.connect_node(circuit.GND, 'A', ['OE', 'D0', 'D1', 'D2', 'D3', 'D4', 'D5', 'D6', 'D7'])
#bgh_offset.connect_node(circuit.VCC, 'A', 'D4')

bgha.connect_node(bgh_offset, 'Q3', 'D3')
bghb.connect_node(bgh_offset, 'Q4', 'D3')
bghb.connect_node(bgh_offset, 'Q5', 'D2')
bghb.connect_node(bgh_offset, 'Q6', 'D1')
bghb.connect_node(bgh_offset, 'Q7', 'D0')

# BG Count V
bgva = circuit.create_ic('BGVCountA', 'SN74HC163N')
bgva.connect_node(va, 'Q0', 'CP')
bgva.connect_node(circuit.VCC, 'A', ['CEP', 'CET'])
bgva.connect_node(v_sr_latch, '1Y', 'PE')
bgva.connect_node(circuit.GND, 'A', 'D0')
bgva.connect_node(circuit.GND, 'A', 'D1')
bgva.connect_node(circuit.GND, 'A', 'D2')

bgvb = circuit.create_ic('BGVCountB', 'SN74HC163N')
bgvb.connect_node(va, 'Q0', 'CP')
bgvb.connect_node(circuit.VCC, 'A', 'CEP')
bgvb.connect_node(bgva, 'TC', 'CET')
bgvb.connect_node(v_sr_latch, '1Y', 'PE')

bgv_offset = circuit.create_ic('BGVOffsetLatch', 'SN74HC373')
bgv_offset.connect_node(circuit.VCC, 'A', 'LE')
bgv_offset.connect_node(circuit.GND, 'A', ['OE', 'D0', 'D1', 'D2', 'D3', 'D4', 'D5', 'D6'])
bgv_offset.connect_node(circuit.VCC, 'A', 'D7')

bgva.connect_node(bgv_offset, 'Q0', 'D0')
bgva.connect_node(bgv_offset, 'Q1', 'D1')
bgva.connect_node(bgv_offset, 'Q2', 'D2')
bgva.connect_node(bgv_offset, 'Q3', 'D3')
bgvb.connect_node(bgv_offset, 'Q4', 'D0')
bgvb.connect_node(bgv_offset, 'Q5', 'D1')
bgvb.connect_node(bgv_offset, 'Q6', 'D2')
bgvb.connect_node(bgv_offset, 'Q7', 'D3')

bgv_reset = circuit.create_ic('BGVReset', 'SN74LS30')
bgv_reset.connect_node(bgvb, 'Q0', 'A')
bgv_reset.connect_node(bgvb, 'Q1', 'B')
bgv_reset.connect_node(bgvb, 'Q2', 'C')
bgv_reset.connect_node(bgvb, 'Q3', 'D')
bgv_reset.connect_node(circuit.VCC, 'A', ['E', 'F', 'G', 'H'])

bgva.connect_node(bgv_reset, 'Y', 'MR')
bgvb.connect_node(bgv_reset, 'Y', 'MR')

bg_sr_latch = circuit.create_ic('BgSrLatch', 'SN74LS00')
bg_sr_latch.connect_node(h_sr_latch, '3Y', '1A')
bg_sr_latch.connect_node(bg_sr_latch, '2Y', '1B')
bg_sr_latch.connect_node(bg_sr_latch, '1Y', '2A')
bg_sr_latch.connect_node(bghb, 'TC', '2B')

bg_sr_latch.connect_node(v_sr_latch, '3Y', '3B')
bg_sr_latch.connect_node(bg_sr_latch, '4Y', '3A')
bg_sr_latch.connect_node(bg_sr_latch, '3Y', '4B')
bg_sr_latch.connect_node(bgv_reset, 'Y', '4A')

framebuffer = numpy.zeros(shape=(525,318,3), dtype=numpy.uint8)
end_count = 333900
#end_count = 320
while circuit.CLK.count < end_count:
    circuit.increment_simulation()
    if circuit._subclock == 0:
        x = BitArray(bin="{}{}{}".format(hc, hb, ha)).uint
        y = BitArray(bin="{}{}{}".format(vc, vb, va)).uint
        if x < 318 and y < 525:
            #h_sync = h_sr_latch.output_value('3Y')*255
            #h_blank = h_sr_latch.output_value('1Y')*255
            #v_sync = v_sr_latch.output_value('3Y')*255
            #v_blank = v_sr_latch.output_value('1Y')*255
            valueh = BitArray(bin="{}{}".format(bghb, bgha)).uint
            valuev = BitArray(bin="{}{}".format(bgvb, bgva)).uint
            h_nametable = bg_sr_latch.output_value('2Y')*127
            v_nametable = bg_sr_latch.output_value('4Y')*127
            framebuffer[y][x] = (valueh, valueh, 0)
    #h_sync = h_sr_latch.output_value('3Y')
    #if (not h_sync and subclock == 0):
    #    log.info("HSYNC")

    #h_blank = h_sr_latch.output_value('1Y')
    #if (not h_blank and subclock == 0):
    #    log.info("HBlank")

    #    if latch:
    #        log.info(CLK)
    #        print("Count : {} - {} - {}".format(vc, vb, va))

img = Image.fromarray(framebuffer, mode='RGB')
img.show()