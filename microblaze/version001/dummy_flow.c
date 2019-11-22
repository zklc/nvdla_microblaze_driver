#include "dla_global_var_use.h"

//初始化全局变量
//包含network的和所有输入、输出的存储空间分配，和对齐
init_global_var();//由程序自动生成。


//by gzk, from network
initial_network_memory();//from network?

while (1) {
  network->input();// 已经放入global_batch_input_array[i].aligned_phy_addr中

  //下面是长时间的阻塞
  while( global_input_num != global_batch_input_num) //global_input_num 在全局变量中设置，网络回调函数设置它的值，
    //这一版，默认global_batch_input_num = 100
    //由于是多个函数共享这个变量，为了减少冲突，这里设置成100，而非大于0
    //默认已经将100个输入按
  {
    for (int i = 0; i < global_btach_input_num; i++) {
      unsigned int input_align_addr = global_batch_input_array[i].aligned_phy_addr;
      unsigned int output_align_addr = global_batch_output_array[i].aligned_phy_addr;
      inference_network (unsigned int input_align_addr, unsigned int output_align_addr);
      global_input_num--;
      }

    //将所有结果送回pc
    //结果放在global_batch_output_array[i].aligned_phy_addr中，以global_batch_output_array[i].aligned_size为大小。
    send_all_result_to_pc();
  }
  



  
}
