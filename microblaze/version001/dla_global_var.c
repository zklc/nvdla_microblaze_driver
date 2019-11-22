//MEMORY_ALIGNMENT不用替换，其他的需要替换。

DLA_GLOBAL_VAR_INIT_FUN {
  DLA_MEMORY_D_NUM = array_num;
  DLA_MEMORY_D_NAME = (memory_d*) malloc (sizeof (memory_d) * array_num);
  for (int i = 0; i < array_num; i++) {
    DLA_MEMORY_D_NAME[i].memory_id = i;
    DLA_MEMORY_D_NAME[i].size = memory_d_array[i].aligned_size + MEMORY_ALIGNMENT;
    DLA_MEMORY_D_NAME[i].phy_addr = (unsigned int ) malloc (DLA_MEMORY_D_NAME[i].size);
    DLA_MEMORY_D_NAME[i].aligned_phy_addr = (DLA_MEMORY_D_NAME[i].phy_addr + MEMORY_ALIGNMEN -1 ) & (~(MEMORY_ALIGNMENT-1))
  }

}
