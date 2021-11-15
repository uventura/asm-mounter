# Counter : From -16 To 16
#==========================================

subi r1,r0,r0,16 # r1 = 16
addi r2,r0,r0,16 # r2 = 16
subi r2,r2,r0,1  # r2 += 1
addi r1,r1,r0,1  # r1 += 1
ble r1,r2,-1     # if(r1 == r2) goto line current_line - 1
beq r1,r1,0      # if(r1 == r1) stop

#==========================================