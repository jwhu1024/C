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

//3�B�o����w�a�}�W���@�Ӧr�`�Φr
#define  MEM_B( x )  ( *( (byte *) (x) ) )
#define  MEM_W( x )  ( *( (word *) (x) ) )

//4�B�D�̤j�ȩM�̤p��
#define  MAX( x, y ) ( ((x) > (y)) ? (x) : (y) )
#define  MIN( x, y ) ( ((x) < (y)) ? (x) : (y) )

//5�B�o��@��field�b���c��(struct)���������q
#define FPOS( type, field ) \
/*lint -e545 */ ( (dword) &(( type *) 0)-> field ) /*lint +e545 */

//6�B�o��@�ӵ��c�餤field�Ҧ��Ϊ��r�`��
#define FSIZ( type, field ) sizeof( ((type *) 0)->field )

//7�B����LSB�榡���Ӧr�`��Ƭ��@��Word
#define  FLIPW( ray ) ( (((word) (ray)[0]) * 256) + (ray)[1] )

//8�B����LSB�榡��@��Word��Ƭ���Ӧr�`
#define  FLOPW( ray, val ) \
  (ray)[0] = ((val) / 256); \
  (ray)[1] = ((val) & 0xFF)

//9�B�o��@���ܶq���a�}�]word�e�ס^
#define  B_PTR( var )  ( (byte *) (void *) &(var) )
#define  W_PTR( var )  ( (word *) (void *) &(var) )

//10�B�o��@�Ӧr������M�C��r�`
#define  WORD_LO(xxx)  ((byte) ((word)(xxx) & 255))
#define  WORD_HI(xxx)  ((byte) ((word)(xxx) >> 8))

//11�B��^�@�Ӥ�X�j���̱���8������
#define RND8( x )       ((((x) + 7) / 8 ) * 8 )

//12�B�N�@�Ӧr���ഫ���j�g
#define  UPCASE( c ) ( ((c) >= 'a' && (c) <= 'z') ? ((c) - 0x20) : (c) )

//13�B�P�_�r�ŬO���O10�i�Ȫ��Ʀr
#define  DECCHK( c ) ((c) >= '0' && (c) <= '9')

//14�B�P�_�r�ŬO���O16�i�Ȫ��Ʀr
#define  HEXCHK( c ) ( ((c) >= '0' && (c) <= '9') ||\
                       ((c) >= 'A' && (c) <= 'F') ||\
					   ((c) >= 'a' && (c) <= 'f') )

//15�B����X���@�Ӥ�k
#define  INC_SAT( val )  (val = ((val)+1 > (val)) ? (val)+1 : (val))

//16�B��^�Ʋդ������Ӽ�
#define  ARR_SIZE( a )  ( sizeof( (a) ) / sizeof( (a[0]) ) )

//17�B ��^�@�ӵL�Ÿ���n������MOD_BY_POWER_OF_TWO(X,n)=X%(2^n)
#define MOD_BY_POWER_OF_TWO( val, mod_by ) \
           ( (dword)(val) & (dword)((mod_by)-1) )

//18�B���IO�Ŷ��M�g�b�s�x�Ŷ������c�A��J��X�B�z
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