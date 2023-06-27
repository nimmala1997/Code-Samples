      TEST_MAIN()
      {
         dv_printf (dv_INFO, " In test blank ");
         uint32_t col_no = 0;
         uint32_t row_no = 12;

         do {
            simtool_wait(1000);
         }while(simtool_getvalue("sys.pkg00.smu_mp5_aied_t.sib_ccd.sib_32_mp5_aied_chiplet_rst_top.ASP_RESETn") != "1'b1");
         aie2ps_init_func();
         connect_tiles_dual_port_wr(col_no);
         memory_load();
         write_to_dram_ct_BD1(col_no, row_no, 0x8000, 1);
         dv_printf(dv_INFO, " Now calling _negative_wr ");
         _negative_wr();
         if(parametersInfo.Def("BUS_LOCKED_CHECK")) {
            do {
               dv_printf(dv_INFO, "signal bus lock not high");
               simtool_wait(10000);
            }while((simtool_getvalue("sys.pkg00.iod.mpu_iod.super_umc0.df_cs_ctrl_umc_t0.cs_ctrl.cs_pg.Regs_BusLocked") != "1'b1")
            || (simtool_getvalue("sys.pkg00.iod.mpu_iod.df_ccm_cpua_t0.ccm_cpu.ccm_ctrl.ccm_pg.DstSdpPg0_ReqCmd[5:0]") != "6'h6" ));
         dv_printf(dv_INFO, " now calling last_write ");
         last_write();
         }
         dv_printf (dv_INFO, " Exit test blank");
      }

         uint32_t col_no;
         uint32_t row_no;
         void aie2ps_negative_wr() {
            col_no=0;
            row_no = 12;
            dv_printf (dv_INFO, " initiating write from shim dma ");
            AXI_WRITE_NIC400(TILE_ADDR(col_no,0, DMA_S2MM_0_CTRL_NOC), 0x00008800);
            dv_printf (dv_INFO, "_negative_wr one function completed ");
            AXI_WRITE_NIC400(TILE_ADDR(col_no,0, DMA_S2MM_0_TASK_QUEUE_NOC), 0x00000001);
            dv_printf (dv_INFO, " _negative_wr two function completed ");
            AXI_WRITE_NIC400(TILE_ADDR(col_no,0, LOCK1_VALUE_NOC), 0x00000001);
            dv_printf (dv_INFO, " \negative_wr three function completed ");
         }

         void last_write() {
            dv_printf (dv_INFO, "  last_write started ");
            AXI_WRITE_NIC400(TILE_ADDR(col_no, row_no, LOCK1_VALUE_MEM), 0x00000001);
            dv_printf (dv_INFO, " last_write completed ");
         }

         void memory_load() {
            col_no=0;
            row_no = 12;      
            dv_printf (dv_INFO, "in memory load function ");
            AXI_WRITE_NIC400(TILE_ADDR(0, row_no, 0x00008000), (uint64)0x00001234);
            dv_printf (dv_INFO, "memory load function completed ");
         }›