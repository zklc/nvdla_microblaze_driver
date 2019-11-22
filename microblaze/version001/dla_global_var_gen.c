#include "dla_global_var_gen.h"
#include "dla_interface_with_system.h"

#include <stdio.h>
//分析网络之后，得到的结果


void gen_dla_global_var_file (char *file_name, dla_network_prop* p_network_prop, memory_d*  memory_d_array, int array_num, int batch_num) {
  FILE *f_out = fopen (file_name, "w");
  fprintf (f_out, "//******Do not modify this file********//\n" );
  fprintf (f_out, "//******generated by program********//\n");

  fprintf (f_out, "#include \"dla_interface_with_system.h\"\n");
  fprintf (f_out, "#include \"data_struct_define_share.h\"\n");
  //split line
  fprintf (f_out, "//////////////////////////////////\n\n");
  fprintf (f_out, "#include <stdio.h>\n");
  fprintf (f_out, "#include <stdlib.h>\n");
  //split line
  fprintf (f_out, "//////////////////////////////////\n\n");
  
  //dump dla_network_prop
  //  fprintf (f_out, "dla_network_prop %s;\n", DLA_NETWORK_PROP_NAME);

  
  
  //dump memory_d_array and number
  fprintf (f_out, "memory_d* %s;\n", DLA_MEMORY_D_NAME);
  fprintf (f_out, "int %s;\n", DLA_MEMORY_D_NUM);
  
  //dump batch input, output and batch number
  fprintf (f_out, "int %s;\n", DLA_BATCH_NUM);
  fprintf (f_out, "memory_d* %s;\n", DLA_BATCH_INPUT);
  fprintf (f_out, "memory_d* %s;\n", DLA_BATCH_OUTPUT);
  //split line
  fprintf (f_out, "//////////////////////////////////\n\n");
  
  //initial function
  fprintf (f_out, "%s {\n", DLA_GLOBAL_VAR_INIT_FUN);
  // fprintf (f_out,"DLA_GLOBAL_VAR_INIT_FUN {
  /*
  fprintf (f_out, "\t%s = %d;\n\
  \t%s = (memory_d*) malloc (sizeof (memory_d) * global_memory_d_num);\n\
  \tfor (int i = 0; i < global_memory_d_num; i++) {\n\
    \t\t%s[i].memory_id = i;\n\
    \t\t%s[i].size = %d + MEMORY_ALIGNMENT;\n\
    \t\t%s[i].phy_addr = (unsigned int ) malloc (%s[i].size);\n\
    \t\t%s[i].aligned_phy_addr = (%s[i].phy_addr + MEMORY_ALIGNMEN -1 ) & (~(MEMORY_ALIGNMENT-1));\n\
    \t\t%s[i].aligned_size = global_memory_d_array[i].aligned_size;\n\
  \t}\n\
}\n\
", DLA_MEMORY_D_NUM, array_num, DLA_MEMORY_D_NAME, DLA_MEMORY_D_NAME,
	   DLA_MEMORY_D_NAME, memory_d_array[i].aligned_size,  DLA_MEMORY_D_NAME,DLA_MEMORY_D_NAME,DLA_MEMORY_D_NAME,DLA_MEMORY_D_NAME,DLA_MEMORY_D_NAME );
  */
  fprintf (f_out, "\t%s = %d;\n", DLA_MEMORY_D_NUM, array_num);
  fprintf (f_out, "\t%s = (memory_d*) malloc (sizeof(memory_d) * %d);\n", DLA_MEMORY_D_NAME, array_num);
  for (int i = 0; i < array_num; i++) {
    fprintf (f_out, "\t%s[%d].memory_id = %d;\n", DLA_MEMORY_D_NAME, i, i );
    fprintf (f_out, "\t%s[%d].size = %d + %d;\n", DLA_MEMORY_D_NAME, i, memory_d_array[i].aligned_size, MEMORY_ALIGNMENT);
    fprintf (f_out, "\t%s[%d].phy_addr = (unsigned int) malloc (%d);\n", DLA_MEMORY_D_NAME, i,
	     memory_d_array[i].aligned_size + MEMORY_ALIGNMENT);
    fprintf (f_out, "\t%s[%d].aligned_phy_addr = (%s[%d].phy_addr + 0x%x -1 ) & (~(0x%x-1));\n",
	     DLA_MEMORY_D_NAME, i, DLA_MEMORY_D_NAME, i, MEMORY_ALIGNMENT, MEMORY_ALIGNMENT);
    fprintf (f_out, "\t%s[%d].aligned_size = %d;\n", DLA_MEMORY_D_NAME, i, memory_d_array[i].aligned_size);
  }

  //split line
  fprintf (f_out, "//////////////////////////////////\n\n");

  fprintf (f_out, "\t%s = (memory_d*) malloc (sizeof (memory_d) * %d);\n", DLA_BATCH_INPUT, batch_num);
  fprintf (f_out, "\t%s = (memory_d*) malloc (sizeof (memory_d) * %d);\n", DLA_BATCH_OUTPUT, batch_num);
  //split line
  fprintf (f_out, "//////////////////////////////////\n\n");

  for (int i = 0; i < batch_num; i++) {
    fprintf (f_out, "\t%s[%d].memory_id = %d;\n", DLA_BATCH_INPUT, i, i );
    fprintf (f_out, "\t%s[%d].size = %d + %d;\n", DLA_BATCH_INPUT, i, memory_d_array[p_network_prop->input_memory_id].aligned_size, MEMORY_ALIGNMENT);
    fprintf (f_out, "\t%s[%d].phy_addr = (unsigned int) malloc (%d);\n", DLA_BATCH_INPUT, i,
	     memory_d_array[p_network_prop->input_memory_id].aligned_size + MEMORY_ALIGNMENT);
    fprintf (f_out, "\t%s[%d].aligned_phy_addr = (%s[%d].phy_addr + 0x%x -1 ) & (~(0x%x-1));\n",
	     DLA_BATCH_INPUT, i, DLA_BATCH_INPUT, i, MEMORY_ALIGNMENT, MEMORY_ALIGNMENT);
    fprintf (f_out, "\t%s[%d].aligned_size = %d;\n", DLA_BATCH_INPUT, i, memory_d_array[p_network_prop->input_memory_id].aligned_size);

  }

  for (int i = 0; i < batch_num; i++) {
    fprintf (f_out, "\t%s[%d].memory_id = %d;\n", DLA_BATCH_OUTPUT, i, i );
    fprintf (f_out, "\t%s[%d].size = %d + %d;\n", DLA_BATCH_OUTPUT, i, memory_d_array[p_network_prop->output_memory_id].aligned_size, MEMORY_ALIGNMENT);
    fprintf (f_out, "\t%s[%d].phy_addr = (unsigned int) malloc (%d);\n", DLA_BATCH_OUTPUT, i,
	     memory_d_array[p_network_prop->output_memory_id].aligned_size + MEMORY_ALIGNMENT);
    fprintf (f_out, "\t%s[%d].aligned_phy_addr = (%s[%d].phy_addr + 0x%x -1 ) & (~(0x%x-1));\n",
	     DLA_BATCH_OUTPUT, i, DLA_BATCH_OUTPUT, i, MEMORY_ALIGNMENT, MEMORY_ALIGNMENT);
    fprintf (f_out, "\t%s[%d].aligned_size = %d;\n", DLA_BATCH_OUTPUT, i, memory_d_array[p_network_prop->output_memory_id].aligned_size);

  }

  

  //batch 
  fprintf (f_out, "\n}");
  fclose (f_out);
}


void gen_dla_global_var_head_file(char *file_name, dla_network_prop* p_network_prop, memory_d*  memory_d_array, int array_num, int batch_num){
  FILE *f_out = fopen (file_name, "w");
  
  fprintf (f_out, "#include \"data_struct_define_share.h\"\n");
  fprintf (f_out, "#include \"dla_interface_with_system.h\"\n");
  
  //extern variable
  //dump memory_d_array and number
  fprintf (f_out, "extern memory_d* %s;\n", DLA_MEMORY_D_NAME);
  fprintf (f_out, "extern int %s;\n", DLA_MEMORY_D_NUM);
  
  //dump batch input, output and batch number
  fprintf (f_out, "extern int %s;\n", DLA_BATCH_NUM);
  fprintf (f_out, "extern memory_d* %s;\n", DLA_BATCH_INPUT);
  fprintf (f_out, "extern memory_d* %s;\n", DLA_BATCH_OUTPUT);
  //split line
  fprintf (f_out, "//////////////////////////////////\n\n");
  
  //dump func

  fprintf (f_out, "%s ;\n", DLA_GLOBAL_VAR_INIT_FUN);
  fclose (f_out);
}

void dummy_test () {
  //假设已经分析完了网络

}

int main () {
  int memory_array_num = 2;
  memory_d memory_array[2];
  memory_array[0].memory_id = 0;
  memory_array[0].size = 10;
  memory_array[0].aligned_size = 10;
  memory_array[1].memory_id = 1;
  memory_array[1].size = 12;
  memory_array[1].aligned_size = 4096;
  int batch_num = 10;

  dla_network_prop np;
  np.input_memory_id = 0;
  np.output_memory_id = 1;
  
  gen_dla_global_var_file ("test_gen_out.c", &np,
			      memory_array, memory_array_num, batch_num);

  gen_dla_global_var_head_file ("test_gen_out.h", &np,
			  memory_array, memory_array_num, batch_num);
}
