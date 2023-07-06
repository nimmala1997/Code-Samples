TEST_MAIN()
{
 
dv_printf (dv_INFO, " In test blank ");\\

  
uint32_t col_no = 0;\\
uint32_t row_no = 12;\\

do {
 simtool_wait(1000);\\
}while(simtool_getvalue("Lock_signal") != "1'b1" );\\
aie2ps_init_func();\\
connection_port(col_no);\\
memory_loading();\\
write_to_DRAM(col_no, row_no, 0x8000, 1);\\
dv_printf(dv_INFO, " Now calling negative_wr ");\\
negative_wr();\\
 dv_printf(dv_INFO,"CDP:sync point  for lock instruction to execute from asm");
      (Register0, 0x55555555, true, 26);


if(parametersInfo.Def("BUS_LOCKED_CHECK")) \\{
do {
dv\_printf(dv_INFO, "signal bus lock not high");\\
simtool_wait(10000);\\
}\\while( \\(simtool_getvalue("Buslock_signal") != "1'b1") ));\\
dv\_printf(dv_INFO, " now calling last_write ");\\
last_write();\\
} \\
 dv\_printf (dv_INFO, " Exit test blank");\\
 
}\\


void negative_wr()\\ {

col_no=0;\\
row_no = 12;   \\     

dv_printf (dv_INFO, " initiating write from shim dma ");\\

AXI_WRITE(TILE_ADDR(col_no,0,), 0x00008800);\\

dv_printf (dv_INFO, " negative_wr one function completed "); \\
AXI_WRITE(TILE_ADDR(col_no,0,), 0x00000001);\\
dv_printf (dv_INFO, "  negative_wr two function completed ");\\
AXI_WRITE(TILE_ADDR(col_no,0,), 0x00000001);\\
dv_printf (dv_INFO, " negative_wr three function completed ");
}\\

void last_write()\\ {

dv_printf (dv_INFO, "  last_write started ");\\
AXI_WRITE(TILE_ADDR(col_no, row_no,), 0x00000001);\\
dv_printf (dv_INFO, " last_write completed ");\\

}

void memory_load()\\ {
col_no=0;\\\
row_no = 12;  \\      
dv_printf (dv_INFO, "  in memory load function ");\\
AXI_WRITE(TILE_ADDR(0, row_no, 0x00008000), (uint64)0x00001234);\\
dv_printf (dv_INFO, " memory load function completed ");\\
}