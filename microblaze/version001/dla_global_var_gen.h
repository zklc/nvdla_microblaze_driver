#ifndef DATA_STRUCT_VAR_GEN_H
#define DATA_STRUCT_VAR_GEN_H
#include "dla_interface_with_system.h"
#include "data_struct_define_share.h"

//输出文件名
//定义
#define GLOBAL_VAR_NAME "dla_global_var.c"
//声明，在使用全局变量的地方，都include，可以在函数块中include
#define USE_GLOBAL_VAR_HEAD "dla_global_var_use.h"

//变量名
//#define DLA_NETWORK_PROP_NAME "global_dla_network_prop"
#define DLA_MEMORY_D_NAME "global_memory_d_array"
#define DLA_MEMORY_D_NUM "global_memory_d_num"
#define BATCH_NUM 100 //一次批量处理的图片数
#define DLA_BATCH_NUM "global_batch_input_num"
#define DLA_BATCH_INPUT "global_batch_input_array" //memory_id
#define DLA_BATCH_OUTPUT "global_batch_output_array" //memory_id

//将上述全局变量初始化。
#define DLA_GLOBAL_VAR_INIT_FUN "void init_global_var()"

void gen_dla_global_var_file (char *file_name, dla_network_prop*, memory_d* memory_d_array, int array_num, int batch_num);

void gen_dla_global_var_head_file(char *file_name, dla_network_prop*, memory_d*  memory_d_array, int array_num, int batch_num);


#endif
