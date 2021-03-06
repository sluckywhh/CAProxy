/********************************************************************
	created:	2010-4-29
	filename: 	HTCSPApi.h
	author:		haitaifangyuan
	
	purpose:	
*********************************************************************/


#ifndef _HTCSPAPI_H_
#define _HTCSPAPI_H_

#include <windows.h>
#include "HYErrorCode.h"



#define HS_HASH_SHA1				0x01
#define HS_HASH_SHA256				0x02
#define HS_HASH_MD2					0x03
#define HS_HASH_MD5					0x04
#define HS_SSL3_SHAMD5              0x05


#define SERIAL_LEN					0x08
#define MAX_RSA_MODULUS_BITS		2048	
#define MAX_RSA_MODULUS_LEN			((MAX_RSA_MODULUS_BITS + 7) / 8)	
#define MAX_RSA_PRIME_BITS			((MAX_RSA_MODULUS_BITS + 1) / 2)	
#define MAX_RSA_PRIME_LEN			((MAX_RSA_PRIME_BITS + 7) / 8)	
#define SO_PIN_LEN                  0x10
#define USER_PIN_LEN                0x10
#define HTCSP_APP_NUM               0x0A

#define HT_NEEDNT_PIN				0x00
#define HT_SO_PIN					0x01
#define HT_USER_PIN					0x02
#define RSA_MODE_1024				0x01
#define RSA_MODE_2048				0x02
#define PIN_LEAD_LEN				0x06
#define HT_UNKNOWN_APP				0x00000000
#define HT_CSP_APP					0x00000001
#define HT_SEC_APP					0x00000004
#define HT_BLANK_HW					0x80000000
#define MAX_CON_NAME_LEN			0x40
#define HT_SSF33_KEY				0x03
#define HT_SCB2_KEY					0x04
#define ENCRYPT_MODE				0x01
#define DECRYPT_MODE 				0x02
#define HT_RSA_PUB_KEY				0x01
#define HT_RSA_PRI_KEY				0x02
#define HT_FILE_NOT_EXIST			0x00
#define HT_FILE_EXIST				0x01
#define HAIKEY1000					0x01
#define HAIKEY2000					0x02
#define HAIKEY3000					0x03
#define HT_UNKNOW_TYPE				0x04
#define ECB_MODE					0x01
#define CBC_MODE					0x02
#define HT_DES_KEY					0x01
#define HT_3DES_112_KEY				0x02
#define HT_SCB2						0x60
#define HS_STATE_EMPTY              0x10
#define HS_STATE_PRESENT            0x20
#define HGS_STATE_EMPTY				0x0010
#define HGS_STATE_PRESENT			0x0020
#define HS_DEVICE_INSERT            0x01
#define HS_DEVICE_REMOVE            0x02
#define HT_LABEL_LEN                0x20

#define HS_READERNAME_MAX           0x40
#define HS_SERIAL_LEN_MAX           0x14
#define HS_PIN_LEN_MAX              0x40

#define HS_EXCHANGE_KEY_EXISTING	0x00000001		// 加密密钥已存在
#define HS_EXCHANGE_CERT_EXISTING	0x00000002		// 加密证书已存在
#define HS_SIGN_KEY_EXISTING		0x00010000		// 签名密钥已存在
#define HS_SIGN_CERT_EXISTING		0x00020000		// 签名证书已存在

#define HS_EXCHANGE_1024			0x00000010		// 加密密钥 1024
#define HS_EXCHANGE_2048			0x00000020		// 加密密钥 2048
#define HS_SIGN_1024				0x00100000		// 签名密钥 1024
#define HS_SIGN_2048				0x00200000		// 签名密钥 2048



#define RSA_ZERO_PADDING			0x00
// #define RSA_PKCS1_PADDING		0x01
// #define RSA_SSLV23_PADDING		0x02
// #define RSA_NO_PADDING			0x03
// #define RSA_PKCS1_OAEP_PADDING	0x04
// #define RSA_X931_PADDING			0x05

#define HS_MAX_FILE_NUM				0x32


#define HS_MIN_FILE_ID					0x0000
#define HS_MAX_FILE_ID					0xFFFF
#define HS_MIN_FILE_SIZE				0x0000
#define HS_MAX_FILE_SIZE				0x8000-3	// 文件的最大长度,32K-3,3字节为内部管理文件用
#define HS_MAX_FILES_NUM				50


#define HS_SM2_SEND                0x01
#define HS_SM2_RECEIVE             0x02


#define IV_LEN						0x20

#define HS_ALG_DES					0x71
#define HS_ALG_3DES					0x72
#define HS_ALG_3DES_112				0x73
#define HS_ALG_RC2					0x74
#define HS_ALG_RC4					0x75
#define HS_ALG_RC5					0x76
#define HS_ALG_SM1					0x91
#define HS_ALG_SSF33				0x92

#define AT_KEYEXCHANGE				1
#define AT_SIGNATURE				2



// #ifndef RSA_PKCS1_PADDING
// #define RSA_PKCS1_PADDING
// #endif




#define HS_SM2_SIGNATURE	0x00020100	// ECC签名算法
#define HS_SM2_EXCHANGE		0x00020200	// ECC密钥交换协议
#define HS_SM2_ENCRYPT	    0x00020400	// ECC加密算法


#define ECC_MAX_XCOORDINATE_BITS_LEN 512
#define ECC_MAX_YCOORDINATE_BITS_LEN 512
#define ECC_MAX_MODULUS_BITS_LEN 512


// 公钥结构
typedef struct _HTCSP_SM2_PUBLIC_ST
{
	DWORD dwAlgID;
	DWORD dwBits;
	BYTE XCoordinate[ECC_MAX_XCOORDINATE_BITS_LEN/8];
	BYTE YCoordinate[ECC_MAX_YCOORDINATE_BITS_LEN/8];
} HTCSP_SM2_PUBLIC_ST;


// 私钥结构
typedef struct _HTCSP_SM2_PRIVATE_ST
{
	DWORD dwAlgID;
	DWORD dwBits;
	BYTE PrivateKey[ECC_MAX_MODULUS_BITS_LEN/8];
} HTCSP_SM2_PRIVATE_ST;


// 私钥运算密文数据
typedef struct _HTCSP_SM2_PRI_CRYPTO_ST
{
	BYTE r[ECC_MAX_XCOORDINATE_BITS_LEN/8];
	BYTE s[ECC_MAX_XCOORDINATE_BITS_LEN/8];
} HTCSP_SM2_Pri_Crypto_ST;


// 公钥运算密文数据
typedef struct _HTCSP_SM2_PUB_CRYPTO_ST
{
	BYTE  XCoordinate[ECC_MAX_XCOORDINATE_BITS_LEN/8];
	BYTE  YCoordinate[ECC_MAX_XCOORDINATE_BITS_LEN/8];
	BYTE  Cipher[ECC_MAX_XCOORDINATE_BITS_LEN/8];
	BYTE  Mac[ECC_MAX_XCOORDINATE_BITS_LEN/8];
	DWORD dwCipherLen;
} HTCSP_SM2_Pub_Crypto_ST;


/*
*@brief 密钥结构，密钥结构体信息。
*@param dwKeyType 密钥类型。
*@param dwKeyID 密钥ID。
*@param pbKey 密钥数据。
*@param dwKeyLen 密钥数据长度。
*@param dwUseRight 密钥使用权限。
*@param dwReserved 保留。
*/
typedef struct _HS_KeyInfo_st
{
	DWORD dwKeyType;
	DWORD dwKeyID;
	BYTE *pbKey;
	DWORD dwKeyLen;
	DWORD dwUseRight;
	DWORD dwReserved;
}HS_KEYINFO, *PHS_KEYINFO;

/*
*@brief 设备基本信息结构，用于保存KEY的基本信息。
*@param dwPID 设备的PID。
*@param dwVID 设备的VID。
*@param pdwTotalSiz 芯片空间总大小。
*@param dwFreeSize 设备的剩余空间大小。
*@param dwCOSVer COS版本号。
*@param dwDevType 设备的型号，包括HAIKEY1000、HAIKEY2000、HAIKEY3000、HT_UNKNOW_TYPE等。
*@param dWKeyCategory 设备的种类，包括HAIKEY_COMMON、HAIKEY_BUTTON、HAIKEY_LCD_BUTTON、
                                      HAIKEY_AUDIO_BUTTON、HAIKEY_FINGERPRINT等。
*@param dwDevBufLen 设备缓冲区长度。
*@param dwChipSerial 芯片序列号（16进制的字符串）。
*/
typedef struct _HYC_DeviceInfo_st
{
	DWORD			dwPID;
	DWORD			dwVID;
	DWORD			dwTotalSize;
	DWORD			dwFreeSize;
	DWORD			dwCOSVer;
	DWORD			dwDevType;
	DWORD			dwKeyCategory;
	DWORD			dwDevBufLen;
	BYTE			szChipSerial[64]; 
	DWORD			dwReserved1;
} HYC_DEVICEINFO, *PHYC_DEVICEINFO;

/*
*@brief 公钥结构，公钥结构体信息。
*@param dwbits 公钥位数。
*@param byodulus n值。
*@param bypublicExponent e值。
*/
typedef struct _HTCSP_RSA_PUB_ST
{
	DWORD dwbits;
	BYTE byModulus[MAX_RSA_MODULUS_LEN];      //n              
	BYTE bypublicExponent[MAX_RSA_MODULUS_LEN];    //e
} HTCSP_RSA_PUBLIC_ST;


/*
*@brief 私钥结构，私钥结构体信息。
*@param dwbits 私钥位数。
*@param byodulus n值。
*@param bypublicExponent e值。
*@param byexponent d值。
*@param byprime p , q 。
*@param byprimeExponent p-1,q-1。
*@param bycoefficient iqmp。
*/
typedef struct _HTCSP_RSA_PRI_ST
{
	DWORD dwbits;
	BYTE byModulus[MAX_RSA_MODULUS_LEN];      //n              
	BYTE bypublicExponent[MAX_RSA_MODULUS_LEN];    //e
	BYTE byexponent[MAX_RSA_MODULUS_LEN];      //d
	BYTE byprime[2][MAX_RSA_PRIME_LEN];    // p, q
	BYTE byprimeExponent[2][MAX_RSA_PRIME_LEN]; //p-1,q-1
	BYTE bycoefficient[MAX_RSA_PRIME_LEN];  //iqmp
} HTCSP_RSA_PRIVATE_ST;


/*
*@brief RSA结构，RSA结构体信息。
*@param ht_RSA_pub_st 公钥结构体。
*@param ht_RSA_pri_st 私钥结构体。
*/
typedef struct _HTCSP_RSA_ST
{
	HTCSP_RSA_PUBLIC_ST ht_RSA_pub_st;
	HTCSP_RSA_PRIVATE_ST ht_RSA_pri_st;
} HTCSP_RSA_ST, *PHTCSP_RSA_ST;




/*
*@brief 证书结构，主要用于做RSA签名时传入传出签名相关数据的数据结构。
*@param chVer 版本号。
*@param szSerial 证书序列号。
*@param szC 国家信息。
*@param szOU 部门信息。
*@param szO 公司信息。
*@param szCN 用户名。
*@param szTimeFrom 有效起始日期。
*@param szTimeTo 有效到期日期。
*@param szIssuer 颁发者。
*@param szIssueTo 颁发给。
*/
typedef struct _cert_info_st
{
	BYTE chVer;
	//modify	BYTE szSerial[SERIAL_LEN = 32];
	BYTE szC[MAX_PATH];
	BYTE szOU[MAX_PATH];
	BYTE szO[MAX_PATH];
	BYTE szCN[MAX_PATH];
	char szL[MAX_PATH];
	char szS[MAX_PATH];
	BYTE szTimeFrom[MAX_PATH];
	BYTE szTimeTo[MAX_PATH];
	BYTE szIssuer[MAX_PATH];
	BYTE szReserved1[MAX_PATH];
	BYTE szReserved2[MAX_PATH];
} HTCSP_CERT_ST, *PHTCSP_CERT_ST;

/*
*@brief 格式化结构，主要用于做格式化操作时传入传出格式化相关数据。
*@param szLabel 设备标识名称，长度为1-32字节。
*@param szSOPin 管理员口令，长度为1-16字节。
*@param dwSOPinRetry	管理员口令重试次数。
*@param szUserPin  用户口令，长度为1-16字节。
*@param dwUserPinRetry 用户口令重试次数。
*/
typedef struct _HS_FORMATINFO
{
	LPCSTR szLabel;
	LPCSTR szSOPin;
	DWORD dwSOPinRetry;
	LPCSTR szUserPin;
	DWORD dwUserPinRetry;
	DWORD dwReserved;
}HS_FORMATINFO, *PHS_FORMATINFO;

/*
*@brief 文件信息结构，主要用于创建文件操作时传入传出格式化相关数据。
*@param dwFileID 文件ID。
*@param dwDeleteRight 文件的删除权限。
*@param dwReadRight 文件的读权限。
*@param dwWriteRight 文件的写权限。
*@param dwFileSize 文件的大小，取值为 0<dwFileLen<=MAX_FILE_LEN。
*/
typedef struct _HS_FILEINFO
{
	DWORD dwFileID;
	DWORD dwDeleteRight;
	DWORD dwReadRight;
	DWORD dwWriteRight;
	DWORD dwFileSize;
	DWORD dwReserved1;
	DWORD dwReserved2;
}HS_FILEINFO, *PHS_FILEINFO;


/*
*@brief 缓存结构体
*@param hCard:设备句柄
*@param szReaderName:读卡器名
*@param szDevSerial:设备序列号
*@param szDevPin:用户口令
*@param dwOperationRecord:操作记录    CSP_SIGN_OPERATION：签名操作    CSP_RSA_OPERATION：生成RSA密钥对操作    CSP_CRYPT_OPERATION：加密操作     CSP_WRITECERT_OPERATION：写证书操作
*@param dwReserve:保留位
*/

typedef struct _HSPin_Cache_st
{
	char   szReaderName[HS_READERNAME_MAX];
	char   szDevSerial[HS_SERIAL_LEN_MAX];
	char   szDevPin[HS_PIN_LEN_MAX];
	DWORD  dwOperationRecord[32];
	DWORD  dwReserve;
}HSPIN_CACHE, *PHSPIN_CACHE;


//////////////////////////////////////////////////////////////////////////
//设备插入处理函数原型，参见函数 HKSetDevChgFunc
typedef DWORD (__stdcall *DEVINSERTED)(IN void *pParam);//输入，设备插入处理函数的参数
//设备拔除处理函数原型，参见函数 HKSetDevChgFunc
typedef DWORD (__stdcall *DEVREMOVED)(IN void *pParam);//输入，设备拔除处理函数的参数

#ifdef __cplusplus
extern "C" {
#endif

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

/*  1.1
* 对Haikey设备进行擦除操作，把haikey设备中所有结构和数据清除
* @param[IN] hCard: 输入，设备句柄
* @return 返回0成功，其它失败 */
DWORD _stdcall HSErase
(
	IN HANDLE hCard
);

/*  1.2
* 对Haikey设备进行格式化操作，把haikey格式化成CSP应用格式的设备
* @param[IN] hCard: 输入，设备句柄
* @param[IN] hsFormatInfo: haikey格式化信息结构，具体参见结构定义
* @return 返回0成功，其它失败 */
DWORD _stdcall HSFormat
(
	IN HANDLE hCard,
	IN HS_FORMATINFO hsFormatInfo
);

/*  1.3
* 读USBKey的名字
* @param[IN] hCard: 输入，设备句柄
* @param[OUT] *pszLabel：返回USBKey的名字
* @param[IN OUT] *pdwLabelLen：输入时，为pszLabel缓冲区的长度；输出时，为USBKey名字的长度，包括结尾的NULL
*                当pszLabel为NULL时，*pdwLabelLen返回USBKey名字的长度，包括结尾的NULL
*                USBKey的名字的最大长度为HT_LABEL_LEN，*pdwLabelLen最大为strlen(pszLabel)+1
* @return 返回0成功，其它失败 */
DWORD _stdcall HSReadLabel
(
	IN HANDLE hCard,
	OUT char *pszLabel,
	IN OUT DWORD *pdwLabelLen
);

/*  1.4
* 修改USBKey的名字----执行该操作需要提前校验用户口令
* @param[IN] hCard: 输入，设备句柄
* @param[IN] szLabel：USBKey的名字，最大长度为HT_LABEL_LEN
* @return 返回0成功，其它失败 */
DWORD _stdcall HSWriteLabel
(
 	IN HANDLE hCard,
	IN LPCSTR szLabel
);

/*  1.5
* 获取设备序列号
* @param[IN] hCard: 输入，设备句柄
* @param[OUT] bSerial[SERIAL_LEN]: 返回设备序列号
* @return 返回0成功，其它失败 */
DWORD _stdcall HSGetSerial
(
	IN HANDLE hCard,
	OUT BYTE bSerial[SERIAL_LEN]
);

/*  1.6
* 取USBKey的总空间
* @param[IN] hCard: 输入，设备句柄
* @param[OUT] *pdwTotalSize：USBKey的总空间大小
* @return 返回0成功，其它失败 */
DWORD _stdcall HSGetTotalSize
(
	IN HANDLE hCard,
	OUT DWORD *pdwTotalSize
);

/*  1.7
* 取USBKey的剩余空间
* @param[IN] hCard: 输入，设备句柄
* @param[OUT] *pdwFreeSize：USBKey的剩余空间大小
* @return 返回0成功，其它失败 */
DWORD _stdcall HSGetFreeSize
(
	IN HANDLE hCard,
	OUT DWORD *pdwFreeSize
);

/*  1.8
* 对Haikey设备进行格式化操作扩展函数
* @param[IN] hCard: 输入，设备句柄
* @return 返回0成功，其它失败 */
DWORD _stdcall HSFormatEx
(
	IN HANDLE hCard
);

/*  1.9
* 对Haikey设备进行格式化操作扩展函数2
* @param[IN] hCard: 输入，设备句柄
* @param[IN] hsFormatInfo: haikey格式化信息结构，具体参见结构定义
* @param[IN] dwRight: 指定MF 下 DF.EF文件的创建删除权限，例如 dwRight = 0x1F3F
*                     高字节表示 MF下DF.EF的创建权限，此处为用户权限
*                     低字节表示 删除MF以及MF下DF.EF的权限，此处为管理员权限
*                     权限类型常用的有3种：0F:不需要权限；1F用户权限；3F管理员权限
* @return 返回0成功，其它失败 */
DWORD _stdcall HSFormatEx2
(
	 IN HANDLE hCard,
	 IN HS_FORMATINFO hsFormatInfo,
	 IN DWORD dwRight
 );

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

/*  2.1
* 取所有读写器名字
* @param[OUT] pszReaderName: 输出，多字符串，所有读写器的名称，
*             如果该值为NULL, 由pdwReaderNameLen返回读写器名字的长度
* @param[IN OUT] pdwReaderNameLen:输入：缓冲区的长度，输出：读写器名称的长度，
* @param[OUT] pdwReaderNum:输出，返回读写器的总个数
* @return 返回0成功，其它失败 */
DWORD _stdcall HSListReaders
(
	OUT LPSTR pszReaderName,
	IN OUT DWORD *pdwReaderNameLen,
	OUT DWORD *pdwReaderNum
);

/*  2.2
* 等待设备拔插事件
* @param[OUT] szDevName: 输出，读写器的名称，
* @param[IN OUT] pdwDevNameLen:输出：读写器名称的长度，
* @param[OUT] pdwEvent:输出，事件
* @return 返回0成功，其它失败 */
DWORD _stdcall HSWaitForDevEvent
(
	OUT char *szDevName,
	IN OUT DWORD *pdwDevNameLen, 
	OUT DWORD *pdwEvent
);

/*  2.3
* 指定读写器名，注册相应的设备插拔处理函数
* @param[IN] szReaderName：输入，读写器名称
* @param[IN] InsertProc：输入，设备插入处理函数
* @param[IN] RemoveProc：输入，设备拔除处理函数
* @param[IN] pProcParam：输入，设备插拔处理函数的参数
* @param[OUT] phEvtHandler：输出，插拔事件处理句柄
//返回0成功，其它失败 */
DWORD _stdcall HSSetDevChgEvent
(
	IN LPCSTR szReaderName,
	IN DEVINSERTED InsertProc,
	IN DEVREMOVED RemoveProc,
	IN void *pProcParam,
	OUT HANDLE *phEvtHandler
);

/*  2.4
* 以插拔事件处理句柄注册设备的插拔处理函数或其参数
* @param[IN] hEvtHandler：输入，插拔事件处理句柄
* @param[IN] InsertProc：输入，设备插入处理函数
* @param[IN] RemoveProc：输入，设备拔除处理函数
* @param[IN] pProcParam：输入，设备插拔处理函数的参数
* @return 返回0成功，其它失败 */
DWORD _stdcall HSSetDevChgEventParam
(
	IN HANDLE hEvtHandler,    
	IN DEVINSERTED InsertProc,
	IN DEVREMOVED RemoveProc, 
	IN void *pProcParam
);

/*  2.5
* 获取读写器状态
* @param[IN] szReaderName: 输入，读写器名称
* @param[OUT] pdwState:输出，读卡器状态. 
	          HS_STATE_EMPTY 读卡器中没有设备 
     	      HS_STATE_PRESENT 读卡器中有设备
* @return 返回0成功，其它失败 */
DWORD _stdcall HSGetDevState
(
	IN LPCSTR szReaderName,
	OUT DWORD *pdwState
);

/*  2.6
* 根据可用设备名连接到一个Haikey设备
* @param[IN] szDevName: 输入，可用设备名
* @param[OUT] phCard: 输出，设备的操作句柄
* @return 返回0成功，其它失败 */
DWORD _stdcall HSConnectDev
(
	IN LPCSTR szDevName,
	OUT HANDLE *phCard
);

/*  2.7
* 断开设备
* @param[IN] hCard: 输入，设备的操作句柄
* @return 返回0成功，其它失败 */
DWORD _stdcall HSDisconnectDev
(
	IN HANDLE hCard
);

/*  2.8
* 开始执行事务处理，即请求以独占方式操作该设备，以支持多应用
* @param[IN] hCard: 输入，设备的操作句柄
* @return 返回0成功，其它失败 */
DWORD _stdcall HSBeginTransaction
(
	IN HANDLE hCard
);

/*  2.9
* 结束当前事务处理，即终止本次对设备的独占访问，以支持多应用
* @param[IN] hCard: 输入，设备的操作句柄
* @return 返回0成功，其它失败 */
DWORD _stdcall HSEndTransaction
(
	IN HANDLE hCard
);

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

/*  3.1
* 写自定义序列号
* @param[IN] hCard: 输入，设备的操作句柄
* @param[IN] pszSerial: 输入，自定义序列号，最长30字节
* @param[IN] dwSerialLen: 输入，自定义序列号长度
* @return 返回0成功，其它失败 */
DWORD _stdcall HSWriteDSN
(
	IN HANDLE hCard,
	IN char *pszSerial,
	IN DWORD dwSerialLen
);

/*  3.2
* 读自定义序列号
* @param[IN] hCard: 输入，设备的操作句柄
* @param[IN OUT] pszSerial: 输出，自定义序列号，最长30字节
* @param[IN OUT] pdwSerialLen: 输出，自定义序列号长度
* @return 返回0成功，其它失败 */
DWORD _stdcall HSReadDSN
(
	IN HANDLE hCard,
	IN OUT char *pszSerial,
	IN OUT DWORD *pdwSerialLen
);

/*  3.3
* 写项目号
* @param[IN] hCard: 输入，设备的操作句柄
* @param[IN] dwPCODE: 输入，项目号
* @return 返回0成功，其它失败 */
DWORD _stdcall HSWritePCODE
(
	IN HANDLE hCard,
	IN DWORD dwPCODE
);

/*  3.4
* 读项目号
* @param[IN] hCard: 输入，设备的操作句柄
* @param[OUT] pdwPCODE: 输出，项目号
* @return 返回0成功，其它失败 */
DWORD _stdcall HSReadPCODE
(
	IN HANDLE hCard,
	OUT DWORD *pdwPCODE
);

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

/*  4.1
* 在haikey设备中创建文件
* @param[IN] hCard: 设备句柄
* @param[IN] FileInfo：文件结构信息
                       文件ID 的范围是(0x0000 - 0xFFFF)
* @return 返回0成功，其它失败 */
DWORD _stdcall HSCreateFile
(
	IN HANDLE hCard,
	IN HS_FILEINFO FileInfo
);

/*  4.2
* 写文件
* @param[IN] hCard: 输入，设备句柄
* @param[IN] dwFileIndex: 输入，文件ID
* @param[IN] dwOffset: 输入，偏移量
* @param[IN] pbData: 写入文件的数据
* @param[IN] dwDataLen: 写入数据的长度
* @return 返回0成功，其它失败 */
DWORD _stdcall HSWriteFile
(
	IN HANDLE hCard,
	IN DWORD dwFileIndex,
	IN DWORD dwOffset,
	IN BYTE *pbData,
	IN DWORD dwDataLen
);

/*  4.3
* 读文件操作
* @param[IN] hCard: 输入设备句柄
* @param[IN] dwFileIndex: 输入，文件ID
* @param[IN] dwOffset: 输入，偏移量
* @param[OUT] *pbData：返回读出的数据
* @param[IN OUT] *pdwReadLen：输入时，表示要读的数据的长度，此时pbData应当已经分配内存；
                              输出时，表示实际读出的数据的长度
*             当pbData为NULL时，返回该文件中所保存数据的长度
*             当*pdwReadLen==MAX_FILE_LEN且pbData!=NULL时，一定能够读出该文件的数据
* @return 返回0成功，其它失败 */
DWORD _stdcall HSReadFile
(
	IN HANDLE hCard,
	IN DWORD dwFileIndex,
	IN DWORD dwOffset,
	OUT BYTE *pbData,
	IN OUT DWORD *pdwReadLen
);

/*  4.4
* 删除文件
* @param[IN] hCard: 输入，设备句柄
* @param[IN] dwFileIndex: 文件ID号
* @return 返回0成功，其它失败 */
DWORD _stdcall HSDeleteFile
(
	IN HANDLE hCard,
	IN DWORD dwFileIndex
);

/*  4.5
* 获取文件的大小
* @param[IN] hCard: 设备的句柄
* @param[IN] dwFileIndex: 文件ID
* @param[OUT] *pdwFileSize: 返回文件的大小
* @return 返回0成功，其它失败 */
DWORD _stdcall HSGetFileSize
(
	IN HANDLE hCard,
	IN DWORD dwFileIndex,
	OUT DWORD *pdwFileSize
);

/*  4.6
* 获取文件的权限
* @param[IN] hCard:　设备句柄
* @param[IN] dwFileIndex: 文件ID号
* @param[IN] dwRightType: 取值可以为HS_DELETE_RIGHT, HS_WRITE_RIGHT, HS_READ_RIGHT
* @param[OUT] *pdwPinType: 返回文件的权限类型,返回值有HT_SO_PIN, HT_USER_PIN, HT_NEEDNT_PIN
* @return 返回0成功，其它失败 */
DWORD _stdcall HSGetFileRight
(
	IN HANDLE hCard,
	IN DWORD dwFileIndex,
	IN DWORD dwRightType,
	OUT DWORD *pdwPinType
);

/*  4.7
* 判断文件是否存在
* @param[IN] hCard: 输入，设备句柄
* @param[IN] dwFileIndex: 文件ID号
* @param[OUT] *pdwFileState: 返回文件状态，返回值为HT_FILE_EXIST, HT_FILE_NOT_EXIST
* @return 返回0成功，其它失败 */
DWORD _stdcall HSHasFileExist
(
	IN HANDLE hCard,
	IN DWORD dwFileIndex,
	OUT DWORD *pdwFileState
);

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

/*  5.1
* 枚举所有密钥容器的名字
* @param[IN] hCard: 输入，设备句柄
* @param[OUT] pszContainerName: 输出，多字符串，所有密钥容器的名称，
*             如果该值为NULL, 由pdwContainerNameLen返回密钥容器名字的长度
* @param[IN OUT] pdwContainerNameLen:输入：缓冲区的长度，输出：密钥容器名称的长度，
* @param[OUT] pdwContainerNum:输出，返回密钥容器的总个数
* @return 返回0成功，其它失败 */
DWORD _stdcall HSListContainers
(
	IN HANDLE hCard,
	OUT LPSTR pszContainersName,
	IN	OUT DWORD *pdwContainersNameLen,
	OUT DWORD *pdwContainerNum
);

/*  5.2
* 获取haikey中Container个数
* @param[IN] hCard: 输入，设备句柄
* @param[OUT] pdwContainerNum: 输出，haikey中Container个数
* @return 返回0成功，其它失败 */
DWORD _stdcall HSGetContainerNum
(
	IN HANDLE hCard,
	OUT DWORD *pdwContainerNum
);

/*  5.3
* 获取Container属性
* @param[IN] hCard: 输入，设备句柄
* @param[IN] pszContainerName：密钥容器名字
* @param[OUT] *pdwContainerParam：返回的密钥容器的属性，其值见说明
* @return 返回0成功，其它失败 */
DWORD _stdcall HSGetContainerParam
(
	IN HANDLE hCard,
	IN LPCSTR pszContainerName,
	OUT DWORD *pdwContainerParam
);

/*  5.4
* 获取Container名称
* @param[IN] hCard: 输入，设备句柄
* @param[IN] dwContainerIndex：要检索的密钥容器的索引值，0<=dwContainerIndex<=*pdwContainerNum-1
* @param[OUT] pszContainerName：返回的密钥容器名字
* 			  当pszContainerName==NUL时，pdwContainerNameLen返回密钥容器名字的长度
* @param[IN OUT] *pdwContainerNameLen：输入时，为pszContainerName缓冲区的长度，
* 			     输出时，为密钥容器名字的长度（包括结尾的NULL字符）
* @param[OUT] *pdwContainerParam：返回的密钥容器的属性，其值见说明??
* @return 返回0成功，其它失败 */
DWORD _stdcall HSGetContainerName
(
	IN HANDLE hCard,
	IN DWORD dwContainerIndex,
	OUT LPSTR pszContainerName,
	IN OUT DWORD *pdwContainerNameLen,
	OUT DWORD *pdwContainerParam
);

/*  5.5
* 创建密钥容器,--执行该操作要首先调用校验用户口令操作
* @param[IN] hCard: 输入，设备句柄
* @param[IN] szContainerName：密钥容器名字，如果szContainerName为NULL或长度为0,
                              则在函数内部生成GUID做为密钥容器的名字
*            密钥容器名字的长度最长为MAX_CON_NAME_LEN
* @return 返回0成功，其它失败 */
DWORD _stdcall HSCreateContainer
(
	IN HANDLE hCard,
	IN LPCSTR szContainerName
);

/*  5.6
* 删除密钥容器--执行该操作需要提前校验用户口令
* @param[IN] hCard: 输入，设备句柄
* @param[IN] szContainerName：密钥容器名字
* @return 返回0成功，其它失败 */
DWORD _stdcall HSDelContainer
(
	IN HANDLE hCard,
	IN LPCSTR szContainerName
);


/*  5.7
* 删除容器中指定的证书与密钥对
* @param[IN] hCard: 输入，设备句柄
* @param[IN] pszContainerName：密钥容器名
* @param[IN] dwKeySpec：证书类型
* @return 返回0成功，其它失败 */
DWORD _stdcall HSDelContainerItem
(
	IN HANDLE hCard,
	IN char *pszContainerName,
	IN DWORD dwKeySpec
);

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

/*  6.1
* 创建应用
* @param[IN] hCard: 输入，设备句柄
* @param[IN] dwAppID: 输入，应用ID(ID范围是 1 - 0x5FFF)
* @param[IN] dwEFCreateRight: 输入，DF下，EF文件的创建权限
* @param[IN] dwEFDeleteRight: 输入，DF下，EF文件的删除权限
* @param[IN] szSOPIN: 输入，DF的SOPIN
* @param[IN] dwSOPINRetries: 输入，DF的SOPIN重试次数
* @param[IN] szUserPIN: 输入，DF的UserPIN
* @param[IN] dwUserPINRetries: 输入，DF的UserPIN重试次数
* @param[OUT] phApp: 输出，应用句柄
* @return 返回0成功，其它失败 */
DWORD _stdcall HSCreateApp
(
	IN HANDLE hCard,
	IN DWORD dwAppID,
	IN DWORD dwEFCreateRight,
	IN DWORD dwEFDeleteRight,
	IN char szSOPIN[SO_PIN_LEN],
	IN DWORD dwSOPINRetries,
	IN char szUserPIN[USER_PIN_LEN],
	IN DWORD dwUserPINRetries,
	OUT HANDLE *phApp
);

/*  6.2
* 打开应用
* @param[IN] hCard: 输入，设备句柄
* @param[IN] dwAppID: 输入，应用ID
* @param[OUT] phApp: 输出，应用句柄
* @return 返回0成功，其它失败 */
DWORD _stdcall HSSelectApp
(
	IN HANDLE hCard,
	IN DWORD dwAppID,
	OUT HANDLE *hApp
);

/*  6.3
* 关闭应用
* @param[IN] hApp: 输入，应用句柄
* @return 返回0成功，其它失败 */
DWORD _stdcall HSCloseApp
(
	IN HANDLE hApp
);

/*  6.4
* 删除应用
* @param[IN] hCard: 输入，设备句柄
* @param[IN] dwAppID: 输入，应用ID
* @return 返回0成功，其它失败 */
DWORD _stdcall HSDeleteApp
(
	IN HANDLE hCard,
	IN DWORD dwAppID
);

/*  6.5
* 枚举应用
* @param[IN] hCard: 输入，设备句柄
* @param[OUT] dwAppID: 输入，应用ID数组
* @param[OUT] pdwAppNum: 输出，应用个数
* @return 返回0成功，其它失败 */
DWORD _stdcall HSListApp
(
	IN HANDLE hCard,
	OUT DWORD dwAppID[HTCSP_APP_NUM],
	OUT DWORD *pdwAppNum
);

/*  6.6
* 取USBKey的应用结构
* @param[IN] hCard: 输入，设备句柄
* @param[OUT] *pdwHWApp：USBKey的应用结构
* @return 返回0成功，其它失败 */
DWORD _stdcall HSGetHWApp
(
	IN HANDLE hCard,
	OUT DWORD *pdwHWApp
);

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

/*  7.1
* 读证书
* @param[IN] hCard: 输入，设备句柄
* @param[IN] szContainerName：密钥容器名字
* @param[IN] dwKeySpec：密钥属性，为AT_KEYEXCHANGE或AT_SIGNATURE之一
* @param[OUT] *pbCert：返回证书数据，der编码，当pbCert==NULL时，pdwCertLen返回证书数据的长度
* @param[IN OUT] *pdwCertLen：输入时，为pbCert缓冲区的长度；输出时，为证书数据的长度
* @return 返回0成功，其它失败 */
DWORD _stdcall HSReadCert
(
	IN HANDLE hCard,
	IN LPCSTR szContainerName,
	IN DWORD dwKeySpec,
	OUT BYTE *pbCert,
	IN OUT DWORD *pdwCertLen
);

/*  7.2
* 写证书
* @param[IN] hCard: 输入，设备句柄
* @param[IN] szContainerName：密钥容器名字
* @param[IN] dwKeySpec：密钥属性，为AT_KEYEXCHANGE或AT_SIGNATURE之一
* @param[IN] *pbCert：证书数据，der编码
* @param[IN] dwCertLen：证书数据的长度
* @return 返回0成功，其它失败 */
DWORD _stdcall HSWriteCert
(
	IN HANDLE hCard,
	IN LPCSTR szContainerName,
	IN DWORD dwKeySpec,
	IN BYTE *pbCert,
	IN DWORD dwCertLen
);

/*  7.3
* 导Pfx/P12证书
* @param[IN] hCard: 输入，设备句柄
* @param[IN] szContainerName：密钥容器名字，如果szContainerName为NULL或长度为0,
                               则在函数内部生成GUID做为密钥容器的名字
*                              密钥容器名字的长度最长为MAX_CON_NAME_LEN
* @param[IN] dwRSAKeySpec：指定证书中的RSA密钥在IE中的属性，AT_KEYEXCHANGE=1或AT_SIGNATURE=2，
                           为其它值（如0）时使用从p12中解析出的RSA密钥属性
* @param[IN] *pbP12Data：PKCS#12证书数据
* @param[IN] dwP12DataLen：PKCS#12证书数据的长度
* @param[IN] szP12PWD：PKCS#12证书的保护口令
* @return 返回0成功，其它失败 */
DWORD _stdcall HSImportP12Cert
(
	IN HANDLE hCard,
	IN LPCSTR szContainerName,
	IN DWORD dwRSAKeySpec,
	IN BYTE *pbP12Data,
	IN DWORD dwP12DataLen,
	IN LPCSTR szP12PWD
);

/*  7.4
* 解析证书信息
* @param[IN] pbCert: 输入，证书数据
* @param[IN] dwCertLen: 输入，证书数据长度
* @param[OUT] pHtcs: 输出，证书信息结构体
* @return 返回0成功，其它失败 */
DWORD _stdcall HSGetCertInfo
(
	IN BYTE *pbCert,
	IN DWORD dwCertLen,
	OUT HTCSP_CERT_ST *pHtcs
);

/*  7.5
* 获取证书扩展项信息
* @param[IN] hCard: 输入，设备句柄
* @param[IN] pbCert: 输入，证书数据
* @param[IN] dwCertLen: 输入，证书数据长度
* @param[IN] szName: 输入，扩展项名
* @param[OUT] szExt: 输出，扩展项信息
* @param[IN OUT] dwExtLen: 输出，扩展项信息数据长度
* @return 返回0成功，其它失败 */
DWORD _stdcall HSGetCertExtInfo
(
	IN HANDLE hCard,
	IN BYTE *pbCert,
	IN DWORD dwCertLen,
	IN char *szName,
	OUT char *szExt,
	IN OUT DWORD *dwExtLen
);

/*  7.6
* 注册读卡器中所有证书
* @param[IN] szReaderName: 输入，设备名
* @param[IN] szCSPName: 输入，CSP名
* @return 返回0成功，其它失败 */
DWORD _stdcall HSRegistCertByReaderName
(
	IN LPCSTR szReaderName,
	IN LPCSTR szCSPName
);

/*  7.7
* 注册一张证书
* @param[IN] pbCert: 输入，证书数据
* @param[IN] dwCertLen: 输入，证书数据长度
* @param[IN] szContainer: 输入，容器名
* @param[IN] szCSPName: 输入，CSP名
* @return 返回0成功，其它失败 */
DWORD _stdcall HSRegistCertByData
(
	IN BYTE *pbCert,
	IN DWORD dwCertLen,
	IN LPCSTR szContainer,
	IN LPCSTR szCSPName
);

/*  7.8
* 注销所有证书
* @return 返回0成功，其它失败 */
DWORD _stdcall HSUnRegistAllCert(IN LPCSTR szCSPName);

/*  7.9
* 注销读卡器中所有证书
* @param[IN] szReaderName: 输入，CSP名
* @param[IN] szReaderName: 输入，容器名
* @return 返回0成功，其它失败 */
DWORD _stdcall HSUnRegistCertByData
(
	IN LPCSTR szCSPName,
	IN LPCSTR szContainer
);

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

/*  8.1
* 校验用户口令
* @param[IN] hCard: 设备句柄
* @param[IN] szUserPin: haikey的用户口令
* @param[OUT] pbRetryNum: 如果口令错误，返回重试次数
* @return 返回0成功，其它失败 */
DWORD _stdcall HSVerifyUserPin
(
	IN HANDLE hCard,
	IN LPCSTR szUserPin,
	OUT DWORD *pdwRetryNum
);

/*  8.2
* 修改用户口令操作
* @param[IN] hCard: 设备句柄
* @param[IN] szOldPin: haikey原用户口令
* @param[IN] szNewPin: haikey新用户口令
* @param[OUT] pbRetryNum: 如果口令错误，返回重试次数
* @return 返回0成功，其它失败 */
DWORD _stdcall HSChangeUserPin
(
	IN HANDLE hCard,
	IN LPCSTR szOldPin,
	IN LPCSTR szNewPin,
	OUT DWORD *pdwRetryNum
);

/*  8.3
* 校验管理员口令
* @param[IN] hCard: 设备句柄
* @param[IN] szSOPin：管理员口令
* @param[OUT] pbRetryNum: 如果口令错误，返回重试次数
* @return 返回0成功，其它失败 */
DWORD _stdcall HSVerifySOPin
(
	IN HANDLE hCard,
	IN LPCSTR szSOPin,
	OUT DWORD *pdwRetryNum
);

/*  8.4
* 修改管理员口令
* @param[IN] hCard: 设备句柄
* @param[IN] szOldPin: haikey原管理员口令
* @param[IN] szNewPin:	haikey新管理员口令
* @param[OUT] pbRetryNum: 如果原口令错误，返回口令的重试次数
* @return 返回0成功，其它失败 */
DWORD _stdcall HSChangeSOPin
(
	IN HANDLE hCard,
	IN LPCSTR szOldPin,
	IN LPCSTR szNewPin,
	OUT DWORD *pdwRetryNum
);

/*  8.5
* 重新设置用户口令
* @param[IN] hCard: 输入，设备句柄
* @param[IN] szSOPin：USBKey的管理员口令
* @param[IN] szNewUserPin：USBKey的新的用户口令
* @param[OUT] pbRetryNum：当USBKey的管理员口令错误时，返回管理员口令还能重试的次数
* @return 返回0成功，其它失败 */
DWORD _stdcall HSReWriteUserPin
(
	IN HANDLE hCard,
	IN LPCSTR szSOPin,
	IN LPCSTR szNewUserPin,
	OUT DWORD *pdwRetryNum
);

/*  8.6
* 写PIN缓存
* @param[IN] psaCachedData: 输入，缓存数据指针
* @param[IN] dwCachedDataLen: 输入，缓存数据长度
* @return 返回0成功，其它失败 */
DWORD _stdcall HSWriteCachedPin
(
	IN char *pszCachedData,
	IN DWORD dwCachedDataLen
);

/*  8.7
* 读PIN缓存
* @param[OUT] psaCachedData: 输出，缓存数据指针
* @param[IN] dwCachedDataLen: 输入，缓存数据长度
* @return 返回0成功，其它失败 */
DWORD _stdcall HSReadCachedPin
(
	OUT char *pszCachedData,
	IN DWORD dwCachedDataLen
);

/*  8.8
* 清PIN缓存
* @param[IN] hCard: 输入，设备名
* @return 返回0成功，其它失败 */
DWORD _stdcall HSClearPin
(
	IN char *pszReaderName
);

/*  8.9
* 清所有PIN缓存
* @return 返回0成功，其它失败 */
DWORD _stdcall HSClearAllPin();


/*  8.10
* 获取用户口令重试次数
* @param[IN] hCard: 输入，设备句柄
* @param[OUT] pdwRetryNum:输出，用户口令重试次数
* @return 返回0成功，其它失败 */
DWORD _stdcall HSGetUserPinRetryNum
(
	IN HANDLE hCard,
	OUT DWORD *pdwRetryNum
);

/*  8.11
* 获取管理员口令重试次数
* @param[IN] hCard: 输入，设备句柄
* @param[OUT] pdwRetryNum:输出，管理员口令重试次数
* @return 返回0成功，其它失败 */
DWORD _stdcall HSGetSOPinRetryNum
(
	IN HANDLE hCard,
	OUT DWORD *pdwRetryNum
);

/*  8.12
* 获取用户口令重试总次数
* @param[IN] hCard: 输入，设备句柄
* @param[OUT] pdwRetryNum:输出，用户口令重试总次数
* @return 返回0成功，其它失败 */
DWORD _stdcall HSGetUserPinRetryNumEx
(
	IN HANDLE hCard,
	OUT DWORD *pdwRetryNum
);

/*  8.13
* 获取管理员口令重试总次数
* @param[IN] hCard: 输入，设备句柄
* @param[OUT] pdwRetryNum:输出，管理员口令重试总次数
* @return 返回0成功，其它失败 */
DWORD _stdcall HSGetSOPinRetryNumEx
(
	IN HANDLE hCard,
	OUT DWORD *pdwRetryNum
);

/*  8.14
* 复位
* @param[IN] hCard: 输入，设备句柄
* @return 返回0成功，其它失败 */
DWORD _stdcall HSReset
(
	IN HANDLE hCard
);

/*  8.15
* 获取是否修改过密码的标识
* @param[IN] hCard: 输入，设备句柄
* @param[OUT] pdwChangePINFlage:输出，密码修改标识
* @return 返回0成功，其它失败 */
DWORD _stdcall HSGetChangePINFlage
(
	IN HANDLE hCard,
	OUT DWORD *pdwChangePINFlage
);

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

/*  9.1
* 硬件生成公私钥对----执行该操作需要提前校验用户口令
* @param[IN] hCard: 设备句柄
* @param[IN] szContainerName：密钥容器名字
* @param[IN] dwKeySpec：密钥属性，为AT_KEYEXCHANGE或AT_SIGNATURE之一
* @return 返回0成功，其它失败 */
DWORD _stdcall HSGenRSA
(
	IN HANDLE hCard,
	IN LPCSTR szContainerName,
	IN DWORD dwKeySpec
);

/*  9.2
* 硬件生成公私钥对-扩展函数
* @param[IN] hCard: 设备句柄
* @param[IN] szContainerName：密钥容器名字
* @param[IN] dwKeySpec：密钥属性，为AT_KEYEXCHANGE或AT_SIGNATURE之一
* @param[IN] dwRSAKeyLen：RSA 长度
* @return 返回0成功，其它失败 */
DWORD _stdcall HSGenRSAEx
(
	IN HANDLE hCard,
	IN LPCSTR szContainerName,
	IN DWORD dwKeySpec,
	IN DWORD dwRSAKeyLen = 1024
);

/*  9.3
* 软件生成RSA公私钥对并导出
* @param[OUT] phtcsp_rsa_st: 输出，RSA结构体指针
* @param[IN] dwRSALen: 输入，RSA长度
* @return 返回0成功，其它失败 */
DWORD _stdcall HSGenRSASoft
(
	OUT HTCSP_RSA_ST *phtcsp_rsa_st,
	IN DWORD dwRSALen = 1024
);

/*  9.4
* 导出RSA公钥
* @param[IN] hCard: 输入，设备句柄
* @param[IN] szContainerName：密钥容器名字
* @param[IN] dwKeySpec：密钥属性，为AT_KEYEXCHANGE或AT_SIGNATURE之一
* @param[OUT] *pbPubKey：返回RSA公钥，PKCS#1的DER编码形式
* @param[IN OUT] *pdwPubKeyLen：输入时，为pbPubKey缓冲区长度；输出时，为RSA公钥的DER长度
* @return 返回0成功，其它失败 */
DWORD _stdcall HSExportRSAPubKey
(
	IN HANDLE hCard,
	IN LPCSTR szContainerName,
	IN DWORD dwKeySpec,
	OUT BYTE *pbPubKey,
	IN OUT DWORD *pdwPubKeyLen
);

/*  9.5
*  导入RSA公钥或私钥，在导入RSA私钥时，将同时导入RSA公钥----执行该操作需要提前校验用户口令
* @param[IN] hCard: 输入，设备句柄
* @param[IN] szContainerName：密钥容器名字
* @param[IN] dwKeySpec：密钥属性，为AT_KEYEXCHANGE或AT_SIGNATURE之一
* @param[IN] dwRSAKeyType：RSA公钥或私钥的类型，为HT_RSA_PUB_KEY或HT_RSA_PRI_KEY之一
* @param[IN] *pbRSAKey：RSA公钥或私钥，PKCS#1的DER编码形式
* @param[IN] dwRSAKeyLen：RSA公钥或私钥长度
* @return 返回0成功，其它失败 */
DWORD _stdcall HSImportRSA
(
	IN HANDLE hCard,
	IN LPCSTR szContainerName,
	IN DWORD dwKeySpec,
	IN DWORD dwRSAKeyType,
	IN BYTE *pbRSAKey,
	IN DWORD dwRSAKeyLen
);

/*  9.6
* 硬件RSA公钥加密
* @param[IN] hCard: 输入，设备句柄
* @param[IN] szContainerName：密钥容器名字
* @param[IN] dwKeySpec：密钥属性，为AT_KEYEXCHANGE或AT_SIGNATURE之一
* @param[IN] dwPadMode：补码模式，为RSA_ZERO_PADDING、RSA_PKCS1_PADDING、
                                    RSA_NO_PADDING、RSA_PKCS1_OAEP_PADDING之一
* @param[IN] *pbInData：输入数据
* @param[IN] dwInDataLen：输入数据长度
* @param[OUT] *pbOutData：输出数据
* @param[IN OUT] *pdwOutDataLen：输入时，为pbOutData缓冲区长度；输出时，为输出数据长度
* @return 返回0成功，其它失败 */
DWORD _stdcall HSRSAEncrypt
(
	IN HANDLE hCard,
	IN LPCSTR szContainerName,
	IN DWORD dwKeySpec,
	IN DWORD dwPadMode,
	IN BYTE *pbInData,
	IN DWORD dwInDataLen,
	OUT BYTE *pbOutData,
	IN OUT DWORD *pdwOutDataLen
);

/*  9.7
* 硬件RSA私钥解密----执行该操作需要提前校验用户口令
* @param[IN] hCard: 输入，设备句柄
* @param[IN] szContainerName：密钥容器名字
* @param[IN] dwKeySpec：密钥属性，为AT_KEYEXCHANGE或AT_SIGNATURE之一
* @param[IN] dwPadMode：补码模式，为RSA_ZERO_PADDING、RSA_PKCS1_PADDING、RSA_NO_PADDING、
                                    RSA_PKCS1_OAEP_PADDING之一
* @param[IN] *pbInData：输入数据
* @param[IN] dwInDataLen：输入数据长度
* @param[OUT] *pbOutData：输出数据
* @param[IN OUT] *pdwOutDataLen：输入时，为pbOutData缓冲区长度；输出时，为输出数据长度
* @return 返回0成功，其它失败 */
DWORD _stdcall HSRSADecrypt
(
	IN HANDLE hCard,
	IN LPCSTR szContainerName,
	IN DWORD dwKeySpec,
	IN DWORD dwPadMode,
	IN BYTE *pbInData,
	IN DWORD dwInDataLen,
	OUT BYTE *pbOutData,
	IN OUT DWORD *pdwOutDataLen
);

/*  9.8
* 软件RSA公钥加密
* @param[IN] ht_RSA_pub_st: 输入，RSA公钥数据结构体
* @param[IN] dwPadMode：补码模式，为RSA_ZERO_PADDING、RSA_PKCS1_PADDING、RSA_NO_PADDING、
                                    RSA_PKCS1_OAEP_PADDING之一
* @param[IN] *pbInData：输入数据
* @param[IN] dwInDataLen：输入数据长度
* @param[OUT] *pbOutData：输出数据
* @param[IN OUT] *pdwOutDataLen：输入时，为pbOutData缓冲区长度；输出时，为输出数据长度
* @return 返回0成功，其它失败 */
DWORD _stdcall HSRSAEncryptSoft
(
	IN HTCSP_RSA_PUBLIC_ST ht_RSA_pub_st,
	IN DWORD dwPadMode,
	IN BYTE *pbInData,
	IN DWORD dwInDataLen,
	OUT BYTE *pbOutData,
	IN OUT DWORD *pdwOutDataLen
);

/*  9.9
* 软件RSA私钥解密
* @param[IN] ht_RSA_pri_st: 输入，RSA私钥数据结构体
* @param[IN] dwPadMode：补码模式，为RSA_ZERO_PADDING、RSA_PKCS1_PADDING、RSA_NO_PADDING、
                                    RSA_PKCS1_OAEP_PADDING之一
* @param[IN] *pbInData：输入数据
* @param[IN] dwInDataLen：输入数据长度
* @param[OUT] *pbOutData：输出数据
* @param[IN OUT] *pdwOutDataLen：输入时，为pbOutData缓冲区长度；输出时，为输出数据长度
* @return 返回0成功，其它失败 */
DWORD _stdcall HSRSADecryptSoft
(
	IN HTCSP_RSA_PRIVATE_ST ht_RSA_pri_st,
	IN DWORD dwPadMode,
	IN BYTE *pbInData,
	IN DWORD dwInDataLen,
	OUT BYTE *pbOutData,
	IN OUT DWORD *pdwOutDataLen
);


/*  9.10
* Append Hash OID
* @param[IN] hCard: 输入，设备句柄
* @param[IN] dwHashAlgID：HASH 算法ID
* @param[IN] *pbInData：输入数据
* @param[IN] dwInDataLen：输入数据长度
* @param[OUT] *pbOutData：输出数据
* @param[IN OUT] *pdwOutDataLen：输入时，为pbOutData缓冲区长度；输出时，为输出数据长度
* @return 返回0成功，其它失败 */
DWORD _stdcall HSHashPadding
(
	IN HANDLE hCard,
	IN DWORD dwHashAlgID,
	IN BYTE *pbInData,
	IN DWORD dwInDataLen,
	OUT BYTE *pbOutData,
	IN OUT DWORD *pdwOutDataLen
);

/*  9.11
* 硬件RSA私钥签名
* @param[IN] hCard: 输入，设备句柄
* @param[IN] szContainerName：密钥容器名字
* @param[IN] dwKeySpec：密钥属性，为AT_KEYEXCHANGE或AT_SIGNATURE之一
* @param[IN] dwPadMode：补码模式，为RSA_ZERO_PADDING、RSA_PKCS1_PADDING、RSA_NO_PADDING之一
* @param[IN] *pbInData：输入数据
* @param[IN] dwInDataLen：输入数据长度
* @param[OUT] *pbOutData：输出数据
* @param[IN OUT] *pdwOutDataLen：输入时，为pbOutData缓冲区长度；输出时，为输出数据长度
* @return 返回0成功，其它失败 */
DWORD _stdcall HSRSASign
(
	IN HANDLE hCard,
	IN LPCSTR szContainerName,
	IN DWORD dwKeySpec,
	IN DWORD dwPadMode,
	IN BYTE *pbInData,
	IN DWORD dwInDataLen,
	OUT BYTE *pbOutData,
	IN OUT DWORD *pdwOutDataLen
);

/*  9.12
* 硬件RSA公钥验证签名
* @param[IN] hCard: 输入，设备句柄
* @param[IN] szContainerName：密钥容器名字
* @param[IN] dwKeySpec：密钥属性，为AT_KEYEXCHANGE或AT_SIGNATURE之一
* @param[IN] dwPadMode：补码模式，为RSA_ZERO_PADDING、RSA_PKCS1_PADDING、RSA_NO_PADDING之一
* @param[IN] *pbInData：输入数据
* @param[IN] dwInDataLen：输入数据长度
* @param[OUT] *pbOutData：输出数据
* @param[IN OUT] *pdwOutDataLen：输入时，为pbOutData缓冲区长度；输出时，为输出数据长度
* @return 返回0成功，其它失败 */
DWORD _stdcall HSRSAVerify
(
	IN HANDLE hCard,
	IN LPCSTR szContainerName,
	IN DWORD dwKeySpec,
	IN DWORD dwPadMode,
	IN BYTE *pbInData,
	IN DWORD dwInDataLen,
	OUT BYTE *pbOutData,
	IN OUT DWORD *pdwOutDataLen
);

/*  9.13
* 软件RSA私钥签名
* @param[IN] ht_RSA_pri_st: 输入，RSA私钥数据结构体
* @param[IN] dwPadMode：补码模式，为RSA_ZERO_PADDING、RSA_PKCS1_PADDING、RSA_NO_PADDING之一
* @param[IN] *pbInData：输入数据
* @param[IN] dwInDataLen：输入数据长度
* @param[OUT] *pbOutData：输出数据
* @param[IN OUT] *pdwOutDataLen：输入时，为pbOutData缓冲区长度；输出时，为输出数据长度
* @return 返回0成功，其它失败 */
DWORD _stdcall HSRSASignSoft
(
	IN HTCSP_RSA_PRIVATE_ST ht_RSA_pri_st,
	IN DWORD dwPadMode,
	IN BYTE *pbInData,
	IN DWORD dwInDataLen,
	OUT BYTE *pbOutData,
	IN OUT DWORD *pdwOutDataLen
);

/*  9.14
* 软件RSA公钥验证签名
* @param[IN] ht_RSA_pub_st: 输入，RSA公钥数据结构体
* @param[IN] dwPadMode：补码模式，为RSA_ZERO_PADDING、RSA_PKCS1_PADDING、RSA_NO_PADDING之一
* @param[IN] *pbInData：输入数据
* @param[IN] dwInDataLen：输入数据长度
* @param[OUT] *pbOutData：输出数据
* @param[IN OUT] *pdwOutDataLen：输入时，为pbOutData缓冲区长度；输出时，为输出数据长度
* @return 返回0成功，其它失败 */
DWORD _stdcall HSRSAVerifySoft
(
	IN HTCSP_RSA_PUBLIC_ST ht_RSA_pub_st,
	IN DWORD dwPadMode,
	IN BYTE *pbInData,
	IN DWORD dwInDataLen,
	OUT BYTE *pbOutData,
	IN OUT DWORD *pdwOutDataLen
);

/*  9.15
* 写密钥，密钥类型可以是DES、3DES_112(16字节)、SSF33密钥、SCB2密钥
* @param[IN] hCard: 输入，设备句柄
* @param[IN] HS_KEYINFO KeyInfo: 密钥信息结构，具体见结构定义
* @return 返回0成功，其它失败 */
DWORD _stdcall HSWriteKey
(
	IN HANDLE hCard,
	IN HS_KEYINFO KeyInfo
);

/*  9.16
* 硬件对称算法高速ECB加解密，密钥类型可以是DES、3DES_112(16字节)、SSF33密钥、SCB2密钥
* @param[IN] hCard: 输入，设备句柄
* @param[IN] dwKeyType：密钥类型，为HT_DES_KEY、HT_3DES_112_KEY、HT_SSF33_KEY、HT_SCB2_KEY之一
* @param[IN] dwMode：加密或解密模式，为ENCRYPT_MODE（加密）或DECRYPT_MODE（解密）
* @param[IN] BYTE *pbInData：输入数据
* @param[IN] dwDataLen：数据长度，必须为16的整数倍，输入数据长度与输出数据长度相等
* @param[OUT] *pbOutData：输出数据
* @return 返回0成功，其它失败 */
DWORD _stdcall HSSymEcb
(
	IN HANDLE hCard,
	IN DWORD dwKeyType,
	IN DWORD dwMode,
	IN BYTE *pbInData,
	IN DWORD dwDataLen,
	OUT BYTE *pbOutData
);

/*  9.17
* 用临时密钥加解密数据
* @param[IN] hCard: 输入，设备句柄
* @param[IN] KeyInfo: 临时密钥结构，具体参见结构定义
* @param[IN] dwMode：加密或解密模式，为ENCRYPT_MODE（加密）或DECRYPT_MODE（解密）
* @param[IN] *pbInData：输入数据
* @param[IN] dwDataLen：数据长度，必须为16的整数倍，输入数据长度与输出数据长度相等
* @param[OUT] *pbOutData：输出数据
* @return 返回0成功，其它失败 */
DWORD _stdcall HSSymSessionEcb
(
	IN HANDLE hCard,
	IN HS_KEYINFO KeyInfo,
	IN DWORD dwMode,
	IN BYTE *pbInData,
	IN DWORD dwDataLen,
	OUT BYTE *pbOutData
);

/*  9.18
* 生成随机数
* @param[IN] hCard: 输入，设备句柄
* @param[IN] dwRandomLen：生成的随机数的长度
* @param[OUT] *pbRandom：生成的随机数
* @return 返回0成功，其它失败 */
DWORD _stdcall HSGenRandom
(
	IN HANDLE hCard,
	IN DWORD dwRandomLen,
	OUT BYTE *pbRandom
);

/*  9.19
* 补码
* @param[IN] dwRSAOpMode: 
* @param[IN] dwPadMode: 补码模式
* @param[IN] dwNLen：RSA密钥的 N 的长度
* @param[IN] BYTE *pbInData：输入数据
* @param[IN] dwDataLen：数据长度，必须为16的整数倍，输入数据长度与输出数据长度相等
* @param[OUT] *pbOutData：输出数据
* @param[IN OUT] pdwOutDataLen：输入时，为pbOutData缓冲区长度；输出时，为输出数据长度
* @return 返回0成功，其它失败 */
DWORD _stdcall HSRSAPad
(
	IN DWORD dwRSAOpMode,
	IN DWORD dwPadMode,
	IN DWORD dwNLen,
	IN BYTE *pbInData,
	IN DWORD dwInDataLen,
	OUT BYTE *pbOutData,
	IN OUT DWORD *pdwOutDataLen
);

/*  9.20
* 软件DES的ECB运算，支持DES、3DES、3DES_112
* @param[IN] *pbKey：DES密钥
* @param[IN] dwKeyLen：DES密钥的长度，可以为8、16或24
* @param[IN] dwMode：加密或解密模式，为ENCRYPT_MODE（加密）或DECRYPT_MODE（解密）
* @param[IN] *pbInData：输入数据
* @param[IN] dwDataLen：数据长度，必须为8的整数倍，输入数据长度与输出数据长度相等
* @param[OUT] *pbOutData：输出数据
* @return 返回0成功，其它失败 */
DWORD _stdcall HSDESEcb
(
	IN CONST BYTE *pbKey,
	IN DWORD dwKeyLen,
	IN DWORD dwMode,
	IN CONST BYTE *pbInData,
	IN DWORD dwDataLen,
	OUT BYTE *pbOutData
);

/*  9.21
* 软件DES的CBC运算，支持DES、3DES、3DES_112，采用PKCS#5补码
* @param[IN] *pbKey：DES密钥
* @param[IN] dwKeyLen：DES密钥的长度，可以为8、16或24
* @param[IN] bIV[8]：初始向量，长度必须为8字节
* @param[IN] dwMode：加密或解密模式，为ENCRYPT_MODE（加密）或DECRYPT_MODE（解密）
* @param[IN] BYTE *pbInData：输入数据
* @param[IN] dwInDataLen：输入数据长度，解密时，必须是8的整数倍
* @param[OUT] *pbOutData：输出数据
* @param[IN OUT] *pdwOutDataLen：输入时，为pbOutData的缓冲区长度；输出时，为输出数据长度
*                 加密时，输出数据长度可能比输入数据长度要长
*                 解密时，输出数据长度可能比输入数据长度要短
*  返回0成功，其它失败 */
DWORD _stdcall HSDESCbc
(
	IN CONST BYTE *pbKey,
	IN DWORD dwKeyLen,
	IN BYTE bIV[8],
	IN DWORD dwMode,
	IN CONST BYTE *pbInData,
	IN DWORD dwInDataLen,
	OUT BYTE *pbOutData,
	IN OUT DWORD *pdwOutDataLen
);

/*  9.22
* SCB2的CBC运算，采用PKCS#5补码
* @param[IN] hCard: 输入，设备句柄
* @param[IN] *pKey：SCB2密钥结构体,KeyID目前只能为0
* @param[IN] bIV[16]：初始向量，长度必须为16字节
* @param[IN] dwMode：加密或解密模式，为ENCRYPT_MODE（加密）或DECRYPT_MODE（解密）
* @param[IN] BYTE *pbInData：输入数据
* @param[IN] dwInDataLen：输入数据长度，解密时，必须是16的整数倍
* @param[OUT] *pbOutData：输出数据
* @param[IN OUT] *pdwOutDataLen：输入时，为pbOutData的缓冲区长度；输出时，为输出数据长度
*                加密时，输出数据长度可能比输入数据长度要长
*                解密时，输出数据长度可能比输入数据长度要短
* @return 返回0成功，其它失败 */
DWORD _stdcall HSSCB2Cbc
(
	IN HANDLE hCard,
	IN HS_KEYINFO *pKey,
	IN BYTE bIV[16],
	IN DWORD dwMode,
	IN CONST BYTE *pbInData,
	IN DWORD dwInDataLen,
	OUT BYTE *pbOutData,
	IN OUT DWORD *pdwOutDataLen
);

/*  9.23
* SHA1 单组杂凑
* @param[IN] *pbData：输入数据
* @param[IN] dwDataLen：输入数据长度
* @param[OUT] bHash[20]：Hash值
* @return 返回0成功，其它失败 */
DWORD _stdcall HSSHA1
(
	IN CONST BYTE *pbData,
	IN DWORD dwDataLen,
	OUT BYTE bHash[20]
);

/*  9.24
* MD5 单组杂凑
* @param[IN] *pbData：输入数据
* @param[IN] dwDataLen：输入数据长度
* @param[OUT] bHash[16]：Hash值
* @return 返回0成功，其它失败 */
DWORD _stdcall HSMD5
(
	IN CONST BYTE *pbData,
	IN DWORD dwDataLen,
	OUT BYTE bHash[16]
);

/*  9.25
* 单组杂凑数据
* @param[IN] dwAlgID：算法标识 HS_HASH_SHA1 ; HS_HASH_SHA256 ; HS_HASH_MD5
* @param[IN] *pbData：输入数据
* @param[IN] dwDataLen：输入数据长度
* @param[OUT] bHash[64]：Hash值
* @param[IN OUT] *pdwHashLen：输入时，为bHash的缓冲区长度；输出时，为输出数据长度
* @return 返回0成功，其它失败 */
DWORD _stdcall HSHashData
(
	IN DWORD dwAlgID,
	IN CONST BYTE *pbData,
	IN DWORD dwDataLen,
	OUT BYTE bHash[64],
	IN OUT DWORD *pdwHashLen
);

/*  9.26
* 软件分组杂凑初始化
* @param[IN] dwAlgID：算法标识 HS_HASH_SHA1 ; HS_HASH_SHA256 ; HS_HASH_MD5 ; HS_SSL3_SHAMD5
* @param[OUT] phHash：输出，杂凑的句柄
* @return 返回0成功，其它失败 */
DWORD _stdcall HSHashInit
(
	IN DWORD dwAlgID,
	OUT HANDLE *phHash
);

/*  9.27
* 分组杂凑
* hHash：输入，杂凑的句柄
* pbData：输入，杂凑的数据
* dwDataLen：输入，杂凑的数据长度
* @return 返回0成功，其它失败 */
DWORD _stdcall HSHashUpdate
(
	IN HANDLE hHash,
	IN BYTE *pbData,
	IN DWORD dwDataLen
);

/*  9.28
* 结束分组杂凑
* hHash：输入，杂凑的句柄
* @param[OUT] pbData：输出，杂凑后的数据
* @param[IN OUT] dwDataLen：输入时，为pHashData的缓冲区长度；输出时，为输出数据长度
* @return 返回0成功，其它失败 */
DWORD _stdcall HSHashFinal
(
	IN HANDLE hHash,
	OUT BYTE *pHashData,
	IN OUT DWORD *pdwHashLen
);

/*  9.29
*  导出RSA公私钥
* @param[IN] hCard: 输入，设备句柄
* @param[IN] szContainerName：密钥容器名字
* @param[IN] dwKeySpec：密钥属性，为AT_KEYEXCHANGE或AT_SIGNATURE之一
* @param[OUT] phtcsp_rsa_st：RSA公私钥结构体
* @return 返回0成功，其它失败 */
DWORD _stdcall HSExportRSA
(
	IN HANDLE hCard,
	IN LPCSTR szContainerName,
	IN DWORD dwKeySpec,
	OUT HTCSP_RSA_ST *phtcsp_rsa_st
);

/*  9.30
*  导入RSA公钥或私钥扩展函数
* @param[IN] hCard: 输入，设备句柄
* @param[IN] szContainerName：密钥容器名字
* @param[IN] dwKeySpec：密钥属性，为AT_KEYEXCHANGE或AT_SIGNATURE之一
* @param[IN] htcsp_rsa_st：RSA结构体
*            当私钥的 dwbits = 0x00时，只导入公钥；当私钥的dwbits != 0x00时，公私钥都导入
* @return 返回0成功，其它失败 */
DWORD _stdcall HSImportRSAEx
(
	 IN HANDLE hCard,
	 IN LPCSTR szContainerName,
	 IN DWORD dwKeySpec,
	 IN HTCSP_RSA_ST htcsp_rsa_st
 );


/*  9.31
*  对称分组算法初始化
* @param[IN] hCard: 输入，设备句柄
* @param[IN] dwAlgID: 输入，算法标识
* @param[IN] pbKey: 输入，密钥数据
* @param[IN] dwKeyBitLen: 输入，密钥数据长度
* @param[IN] bIV: 输入，初始化向量
* @param[IN] dwIVLen: 输入，初始化向量长度
* @param[IN] pbSalt: 输入，盐
* @param[IN] dwSaltLen: 输入，盐长度
* @param[IN] dwModeOperation: 输入，运算模式，为ECB_MODE 或者 CBC_MODE
* @param[IN] dwEncrypt: 输入，加解密模式，为 ENCRYPT_MODE 或者 DECRYPT_MODE
* @param[IN] hSymContext: 输出，分组运算句柄
* @return 返回0成功，其它失败 */
DWORD _stdcall HSSymInit(IN HANDLE hCard, IN DWORD dwAlgID, IN BYTE *pbKey, IN DWORD dwKeyBitLen,
						 IN BYTE bIV[IV_LEN], IN DWORD dwIVLen, IN BYTE *pbSalt, IN DWORD dwSaltLen,
						 IN DWORD dwModeOperation, IN DWORD dwEncrypt, OUT HANDLE *hSymCtx);


/*  9.32
*  对称分组算法
* @param[IN] hCard: 输入，设备句柄
* @param[IN] hSymContext: 输入，分组运算句柄
* @param[IN] pbInData: 输入，加密数据
* @param[IN] dwInDataLen: 输入，加密数据长度
* @return 返回0成功，其它失败 */
DWORD _stdcall HSSymUpdate(IN HANDLE hCard, IN HANDLE hSymCtx, IN BYTE *pbInData, IN DWORD dwInDataLen,
						   OUT BYTE *pbOutData, IN OUT DWORD *pdwOutDataLen);


/*  9.33
*  结束对称分组算法
* @param[IN] hCard: 输入，设备句柄
* @param[IN] hSymContext: 输入，分组运算句柄
* @param[IN] pbInData: 输出，加密结果缓冲区
* @param[IN] pdwOutDataLen: 输入，加密结果缓冲区大小，
                            输出，加密数据结果的数据长度
* @return 返回0成功，其它失败 */
DWORD _stdcall HSSymFinal
(
	IN HANDLE hCard, 
	IN HANDLE hSymCtx,
	OUT BYTE *pbOutData, 
	IN OUT DWORD *pdwOutDataLen
);


/*  9.34
*  导入RSA公钥或私钥 扩展函数
* @param[IN] hCard: 输入，设备句柄
* @param[IN] pszContainerName: 输入，容器名
* @param[IN] pszAccounts: 输入，账号
* @param[IN] dwAccountsLen: 输入，账号数据长度
* @param[IN] pszNum: 输入，金额
* @param[IN] dwNumLen: 输入，金额数据长度
* @param[OUT] pbSignature: 输出，签名值
* @param[IN OUT] pdwSignatureLen: 输入输出，签名值长度
* @return 返回0成功，其它失败 */
DWORD _stdcall HSRSASignLCD
(
	IN HANDLE hCard, 
	IN char *pszContainerName,
	IN char *pszAccounts, 
	IN DWORD dwAccountsLen,
	IN char *pszNum, 
	IN DWORD dwNumLen, 
	OUT BYTE *pbSignature, 
	IN OUT DWORD *pdwSignatureLen
);

/*  9.35
*  导入SSF33加密的RSA密钥对
* @param[IN] hCard: 输入，设备句柄
* @param[IN] pszContainerName: 输入，容器名
* @param[IN] dwKeySpec：密钥属性
* @param[IN] pbData: 输入，公私钥密文
* @param[IN] dwDataLen: 输入，公私钥密文长度
* @param[IN] pbKey: 输入，33会话密钥
* @return 返回0成功，其它失败 */
DWORD _stdcall HS33ImprotRSA
(
 IN HANDLE hCard, 
 IN char *pszContainerName,
 IN DWORD dwKeySpec,
 IN BYTE *pbData, 
 IN DWORD dwDataLen,
 IN BYTE *pbKey
 );

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

/*  10.1
* 取KEY时间
* @param[IN] hCard：输入，设备句柄
* @param[OUT] pSystime：输出，KEY的时间数据
* @return 返回0成功，其它失败 */
DWORD _stdcall HSGetTimepiece
(
	IN HANDLE hCard,
	OUT SYSTEMTIME *pSystime
);

/*  10.2
* 取设备类型
* @param[IN] hCard：输入，设备句柄
* @param[OUT] pbData：输出，设备类型数据
* @return 返回0成功，其它失败 */
DWORD _stdcall HSGetDeviceInfo
(
	IN HANDLE hCard,
	OUT HYC_DEVICEINFO *pDeviceSt
);

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

// 11 OpenSSL 函数

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

// 12 配置文件函数

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////


/*  13.1
* 生成SM2签名密钥对
* @param[IN] hCard: 输入，设备句柄
* @param[IN] pszContainerName: 输入，容器名
* @param[IN] dwAlgID: 输入，算法标识，目前只支持 HS_SM2_SIGNATURE
* @param[OUT] pht_ECC_pub_st: 输出，ECC公钥结构体
* @return 返回0成功，其它失败 */
DWORD _stdcall HSGenSM2KeyPair
(
	IN HANDLE hCard, 
	IN char *pszContainerName, 
	IN DWORD dwAlgID, 
	OUT HTCSP_SM2_PUBLIC_ST *pht_SM2_pub_st
);

/*  13.2
* SM2根据指定容器签名
* @param[IN] hCard: 输入，设备句柄
* @param[IN] pszContainerName: 输入，容器名
* @param[IN] pbData: 输入，待签名的数据
* @param[IN] dwDataLen: 输入，待签名数据长度，必须小于密钥模长
* @param[OUT] pht_SM2_Pri_Crypto_st: 输出，签名值
* @return 返回0成功，其它失败 */
DWORD _stdcall HSSM2SignByCon
(
	IN HANDLE hCard, 
	IN char *pszContainerName, 
	IN BYTE *pbInData, 
	IN DWORD dwInDataLen, 
	OUT HTCSP_SM2_Pri_Crypto_ST *pht_SM2_Pri_Crypto_st
);

/*  13.3
* SM2根据指定容器解密
* @param[IN] hCard: 输入，设备句柄
* @param[IN] pszContainerName: 输入，容器名
* @param[IN] pht_SM2_Pub_Crypto_st: 输入，待解密的密文数据
* @param[OUT] pbOutData: 输出，明文数据
* @param[IN OUT] pdwOutDataLen: 输入时表示缓冲区长度，输出时表示明文数据长度
* @return 返回0成功，其它失败 */
DWORD _stdcall HSSM2DecryptByCon
(
	IN HANDLE hCard, 
	IN char *pszContainerName, 
	IN HTCSP_SM2_Pub_Crypto_ST *pht_SM2_Pub_Crypto_st, 
	OUT BYTE *pbOutData, 
	IN OUT DWORD *pdwOutDataLen
);

/*  13.4
* SM2私钥签名
* @param[IN] hCard: 输入，设备句柄
* @param[IN] pht_SM2_pub_st: 输入，SM2公钥数据
* @param[IN] pht_SM2_pri_st: 输入，SM2私钥数据
* @param[IN] pbInData: 输入，待签名数据
* @param[IN] dwInDataLen: 输入，待签名数据的长度
* @param[OUT] pht_SM2_Pri_Crypto_st: 输出，签名值
* @return 返回0成功，其它失败 */
DWORD _stdcall HSSM2Sign
(
	IN HANDLE hCard, 
	IN HTCSP_SM2_PUBLIC_ST *pht_SM2_pub_st, 
	IN HTCSP_SM2_PRIVATE_ST *pht_SM2_pri_st,
	IN BYTE *pbInData, 
	IN DWORD dwInDataLen, 
	OUT HTCSP_SM2_Pri_Crypto_ST *pht_SM2_Pri_Crypto_st
);

/*  13.5
* SM2公钥验签
* @param[IN] hCard: 输入，设备句柄
* @param[IN] pht_SM2_pub_st: 输入，SM2公钥数据
* @param[IN] pbInData: 输入，待验证签名的数据
* @param[IN] dwInDataLen: 输入，数据长度
* @param[IN] pht_SM2_Pri_Crypto_st: 输入，待验证签名值
* @return 返回0成功，其它失败 */
DWORD _stdcall HSSM2Verify
(
	IN HANDLE hCard, 
	IN HTCSP_SM2_PUBLIC_ST *pht_SM2_pub_st,
	IN BYTE *pbInData, 
	IN DWORD dwInDataLen,
	IN HTCSP_SM2_Pri_Crypto_ST *pht_SM2_Pri_Crypto_st
);

/*  13.6
* SM2公钥加密
* @param[IN] hCard: 输入，设备句柄
* @param[IN] pht_SM2_pub_st: 输入，SM2公钥数据
* @param[IN] pbInData: 输入，待加密的明文数据
* @param[IN] dwInDataLen: 输入，待加密明文数据的长度
* @param[OUT] pht_SM2_Pub_Crypto_st: 输出，加密后的密文数据
* @return 返回0成功，其它失败 */
DWORD _stdcall HSSM2Encrypt
(
	IN HANDLE hCard, 
	IN HTCSP_SM2_PUBLIC_ST *pht_SM2_pub_st,
	IN BYTE *pbInData, 
	IN DWORD dwInDataLen, 
	OUT HTCSP_SM2_Pub_Crypto_ST *pht_SM2_Pub_Crypto_st
);

/*  13.7
* SM2私钥解密
* @param[IN] hCard: 输入，设备句柄
* @param[IN] pht_SM2_pri_st: 输入，SM2私钥数据
* @param[IN] pht_SM2_Pub_Crypto_st: 输入，待解密的密文数据
* @param[OUT] pbOutData: 输出，明文数据
* @param[IN OUT] pdwOutDataLen: 输入时表示缓冲区长度，输出时表示明文数据长度
* @return 返回0成功，其它失败 */
DWORD _stdcall HSSM2Decrypt
(
	IN HANDLE hCard, 
	IN HTCSP_SM2_PRIVATE_ST *pht_SM2_pri_st, 
	IN HTCSP_SM2_Pub_Crypto_ST *pht_SM2_Pub_Crypto_st, 
	OUT BYTE *pbOutData, 
	IN OUT DWORD *pdwOutDataLen
);

/*  13.8
* SM2密钥协商初始化
* @param[IN] hCard: 输入，设备句柄
* @param[IN] pht_SM2_pri_st: 输入，SM2私钥数据
* @param[IN] pht_SM2_Pub_Crypto_st: 输入，待解密的密文数据
* @param[OUT] pbOutData: 输出，明文数据
* @param[IN OUT] pdwOutDataLen: 输入时表示缓冲区长度，输出时表示明文数据长度
* @return 返回0成功，其它失败 */
DWORD _stdcall HSSM2KeyAgreementInit
(
	IN HANDLE hCard, 
	IN char *pszContainerName, 
	OUT HTCSP_SM2_PUBLIC_ST *pht_SM2_pub_st, 
	OUT HTCSP_SM2_PUBLIC_ST *pht_SM2_pub_Temp_st, 
	OUT BYTE *pbIDData, 
	IN OUT DWORD *pdwIDDataLen
);


/*  13.9
* SM2密钥协商
* @param[IN] hCard: 输入，设备句柄
* @param[IN] dwAlgID: 输入，算法ID，支持 HS_SM1_KEY    HS_SSF33_KEY
* @param[IN] KeyAgreementType: 输入，SM2发送方或者接收方 HS_SM2_SEND  HS_SM2_RECEIVE
* @param[IN] pszContainerName: 输入，容器名
* @param[IN] pht_SM2_Opposite_pub_st: 输入，对方SM2公钥数据
* @param[IN] pht_SM2_Opposite_pub_Temp_st: 输入，对方SM2临时公钥数据
* @param[IN] pbOppositeIDData: 输入，对方ID数据
* @param[IN] pdwOppositeIDDataLen: 输入，对方ID数据长度
* @return 返回0成功，其它失败 */
DWORD _stdcall HSSM2KeyAgreement
(
	IN HANDLE hCard, 
	IN DWORD dwAlgID, 
	IN DWORD KeyAgreementType, 
	IN char *pszContainerName, 
	IN HTCSP_SM2_PUBLIC_ST *pht_SM2_Opposite_pub_st, 
	IN HTCSP_SM2_PUBLIC_ST *pht_SM2_Opposite_pub_Temp_st, 
	IN BYTE *pbOppositeIDData, 
	IN DWORD *pdwOppositeIDDataLen
);


/*  13.10
* 生成会话密钥并使用SM2公钥加密导出
* @param[IN] hCard: 输入，设备句柄
* @param[IN] dwAlgID: 输入，算法ID，支持 HS_SM1_KEY    HS_SSF33_KEY
* @param[IN] pht_SM2_pub_st: 输入，SM2公钥结构
* @param[IN] pbSessionKey: 输出，使用指定的SM2公钥加密的会话密钥
* @param[IN] pdwSessionKeyLen: 输入时为缓冲区长度，输出时为会话密钥长度
* @return 返回0成功，其它失败 */
DWORD _stdcall HSSM2ExportSessionKey
(
	IN HANDLE hCard, 
	IN DWORD dwAlgID, 
	IN HTCSP_SM2_PUBLIC_ST *pht_SM2_pub_st, 
	OUT BYTE *pbSessionKey, 
	IN OUT DWORD *pdwSessionKeyLen
);

/*  13.11
* 导入由SM2公钥加密的 会话密钥
* @param[IN] hCard: 输入，设备句柄
* @param[IN] dwAlgID: 输入，算法ID，支持 HS_SM1_KEY    HS_SSF33_KEY
* @param[IN] pszContainerName: 输入，容器名
* @param[IN] pbSessionKey: 输入，SM2公钥加密的会话密钥
* @param[IN] dwSessionKeyLen: 输入，SM2公钥加密的会话密钥长度
* @return 返回0成功，其它失败 */
DWORD _stdcall HSSM2ImportSessionKey
(
	IN HANDLE hCard, 
	IN DWORD dwAlgID, 
	IN char *pszContainerName, 
	IN BYTE *pbSessionKey, 
	IN DWORD dwSessionKeyLen
);

/*  13.12
* 导入SM1加密的SM2密钥对
* @param[IN] hCard: 输入，容器名
* @param[IN] pszContainerName: 输入，容器名
* @param[IN] pbPubKey: 输入，SM2公钥密文数据
* @param[IN] dwPubKeyLen: 输入，SM2公钥密文数据长度
* @param[IN] pbPriKey: 输入，SM2私钥密文数据
* @param[IN] dwPriKeyLen: 输入，SM2私钥密文数据长度
* @return 返回0成功，其它失败 */
DWORD _stdcall HSImportSM2
(
	IN HANDLE hCard, 
	IN char *pszContainerName, 
	IN BYTE *pbPubKey, 
	IN DWORD dwPubKeyLen, 
	IN BYTE *pbPriKey, 
	IN DWORD dwPriKeyLen
);












//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
}
#endif



#endif