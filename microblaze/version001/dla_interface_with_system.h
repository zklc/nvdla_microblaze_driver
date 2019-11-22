#ifndef DLA_INTERFACE_WITH_SYSTEM_H
#define DLA_INTERFACE_WITH_SYSTEM_H

#include "data_struct_define_share.h"


//主要用于输入和输出的属性查找。
struct st_dla_network_prop {
  int input_memory_id;
  int output_memory_id;
};
typedef struct st_dla_network_prop dla_network_prop;


//包含network的和所有输入、输出的存储空间分配，和对齐
//void malloc_all_memory(memory_d *p_network_memory_array, int network_memory_array_num,
//		       memory_d *p_batch_input_memory_array,
//		       memory_d *p_batch_output_memory_array,
//		       int batch_memory_num);

//by gzk
//如果管总在网络收包的回调函数中，已经都逐个放入了网络的参数，那么，这里象征性的调用即可，可以不做任何事。
//管总在存放数据的时候，注意请用对齐的地址。
//p_network_memory_array[i].aligned_phy_addr
void initial_network_memory(memory_d *p_network_memroy_array, int network_memory_array_num);

//进行一次推理，结果存放到相应输出。
void inference_network (unsigned int input_align_addr, unsigned int output_align_addr);


#endif
