#include <stdio.h>

typedef  unsigned char      boolean;     /* Boolean value type. */
typedef  unsigned long int  uint32;      /* Unsigned 32 bit value */
typedef  unsigned short     uint16;      /* Unsigned 16 bit value */
typedef  unsigned char      uint8;       /* Unsigned 8  bit value */
typedef  signed long int    int32;       /* Signed 32 bit value */
typedef  signed short       int16;       /* Signed 16 bit value */
typedef  signed char        int8;        /* Signed 8  bit value */
typedef  unsigned char     byte;         /* Unsigned 8  bit value type. */
typedef  unsigned short    word;         /* Unsinged 16 bit value type. */
typedef  unsigned long     dword;        /* Unsigned 32 bit value type. */
typedef  unsigned char     uint1;        /* Unsigned 8  bit value type. */
typedef  unsigned short    uint2;        /* Unsigned 16 bit value type. */
typedef  unsigned long     uint4;        /* Unsigned 32 bit value type. */
typedef  signed char       int1;         /* Signed 8  bit value type. */
typedef  signed short      int2;         /* Signed 16 bit value type. */
typedef  long int          int4;         /* Signed 32 bit value type. */
typedef  signed long       sint31;       /* Signed 32 bit value */
typedef  signed short      sint15;       /* Signed 16 bit value */
typedef  signed char       sint7;        /* Signed 8  bit value */

//3、得到指定地址上的一個字節或字
#define  MEM_B( x )  ( *( (byte *) (x) ) )
#define  MEM_W( x )  ( *( (word *) (x) ) )

//4、求最大值和最小值
#define  MAX( x, y ) ( ((x) > (y)) ? (x) : (y) )
#define  MIN( x, y ) ( ((x) < (y)) ? (x) : (y) )

//5、得到一個field在結構體(struct)中的偏移量
#define FPOS( type, field ) \
/*lint -e545 */ ( (dword) &(( type *) 0)-> field ) /*lint +e545 */

//6、得到一個結構體中field所佔用的字節數
#define FSIZ( type, field ) sizeof( ((type *) 0)->field )

//7、按照LSB格式把兩個字節轉化為一個Word
#define  FLIPW( ray ) ( (((word) (ray)[0]) * 256) + (ray)[1] )

//8、按照LSB格式把一個Word轉化為兩個字節
#define  FLOPW( ray, val ) \
  (ray)[0] = ((val) / 256); \
  (ray)[1] = ((val) & 0xFF)

//9、得到一個變量的地址（word寬度）
#define  B_PTR( var )  ( (byte *) (void *) &(var) )
#define  W_PTR( var )  ( (word *) (void *) &(var) )

//10、得到一個字的高位和低位字節
#define  WORD_LO(xxx)  ((byte) ((word)(xxx) & 255))
#define  WORD_HI(xxx)  ((byte) ((word)(xxx) >> 8))

//11、返回一個比X大的最接近的8的倍數
#define RND8( x )       ((((x) + 7) / 8 ) * 8 )

//12、將一個字母轉換為大寫
#define  UPCASE( c ) ( ((c) >= 'a' && (c) <= 'z') ? ((c) - 0x20) : (c) )

//13、判斷字符是不是10進值的數字
#define  DECCHK( c ) ((c) >= '0' && (c) <= '9')

//14、判斷字符是不是16進值的數字
#define  HEXCHK( c ) ( ((c) >= '0' && (c) <= '9') ||\
                       ((c) >= 'A' && (c) <= 'F') ||\
					   ((c) >= 'a' && (c) <= 'f') )

//15、防止溢出的一個方法
#define  INC_SAT( val )  (val = ((val)+1 > (val)) ? (val)+1 : (val))

//16、返回數組元素的個數
#define  ARR_SIZE( a )  ( sizeof( (a) ) / sizeof( (a[0]) ) )

//17、 返回一個無符號數n尾的值MOD_BY_POWER_OF_TWO(X,n)=X%(2^n)
#define MOD_BY_POWER_OF_TWO( val, mod_by ) \
           ( (dword)(val) & (dword)((mod_by)-1) )

//18、對於IO空間映射在存儲空間的結構，輸入輸出處理
  #define inp(port)         (*((volatile byte *) (port)))
  #define inpw(port)        (*((volatile word *) (port)))
  #define inpdw(port)       (*((volatile dword *)(port)))
  #define outp(port, val)   (*((volatile byte *) (port)) = ((byte) (val)))
  #define outpw(port, val)  (*((volatile word *) (port)) = ((word) (val)))
  #define outpdw(port, val) (*((volatile dword *) (port)) = ((dword) (val)))
  
void main (void)
{
	return;
}