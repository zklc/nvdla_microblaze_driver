#ifndef DATA_STRUCT_DEFINE_SHARE_H
#define DATA_STRUCT_DEFINE_SHARE_H

//内存对齐边界。In fact, 32 bytes may be enough.
#define MEMORY_ALIGNMENT 4096

struct st_memory_d {
  int memory_id;
  int config;// need initialization
  unsigned int phy_addr;
  unsigned int size;//malloced size,只是用于初始化，比loadable定义的格式稍大, size = aligned_size + MEMORY_ALIGNMENT
  unsigned int aligned_phy_addr;//实际使用的地址
  unsigned int aligned_size;//实际实用的大小
};
typedef struct st_memory_d memory_d;



#endif
