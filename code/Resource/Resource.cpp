#include "./Resource.h"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

unsigned char* XYY_Resource::xyy_stbi_load(const char *filename,int * x,int * y,int * comp,int req_comp)
{
	return stbi_load(filename,x,y,comp,req_comp);
}

void XYY_Resource::xyy_stbi_image_free(void * ret_val_from_stbi_load)
{
	stbi_image_free(ret_val_from_stbi_load);
}
