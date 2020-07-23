#include <stdio.h>
#include <inttypes.h>
#include <sys/types.h>

int main()
{
	printf("Sizes of all data types:\n");
	printf("Syntax: data_type (format_specifier)-> size\n\n");
	printf("int (d)-> %d\n",sizeof(int));
	printf("unsigned int (u)-> %d\n\n",sizeof(unsigned int));
	printf("short (h)-> %d\n",sizeof(short));
	printf("unsigned short (hu)-> %d\n\n",sizeof(unsigned short));
	printf("long (ld)-> %d (Has atleast 32 bits)\n",sizeof(long));
	printf("unsigned long (lu)-> %d\n\n",sizeof(unsigned long));
	printf("long long (lld)-> %d (Has atleast 64 bits)\n",sizeof(long long));
	printf("unsigned long long (llu)-> %d\n\n",sizeof(unsigned long long));
	printf("uint8_t (\"\%\"PRIu8)-> %d\n",sizeof(uint8_t));
	printf("uint16_t (\"\%\"PRIu16)-> %d\n",sizeof(uint16_t));
	printf("uint32_t (\"\%\"PRIu32)-> %d\n",sizeof(uint32_t));
	printf("uint64_t (\"\%\"PRIu64)-> %d\n\n",sizeof(uint64_t));
	printf("u_int8_t in sys/types.h-> %d\n",sizeof(u_int8_t));
	printf("u_int16_t in sys/types.h-> %d\n",sizeof(u_int16_t));
	printf("u_int32_t in sys/types.h-> %d\n",sizeof(u_int32_t));
	printf("u_int64_t in sys/types.h-> %d\n\n",sizeof(u_int64_t));
	printf("float (f)-> %d\n",sizeof(float));
	printf("double (lf)-> %d\n\n",sizeof(double));
	printf("long double (Lf)-> %d\n\n",sizeof(long double));
	printf("char (c)-> %d\n",sizeof(char));
	printf("unsigned char (c)-> %d\n",sizeof(unsigned char));
}
