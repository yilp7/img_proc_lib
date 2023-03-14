
#ifndef _MV_OBSOLETE_CAM_PARAMS_H_
#define _MV_OBSOLETE_CAM_PARAMS_H_

#include "PixelType.h"

/// \~chinese 输出帧的信息             \~english Output Frame Information
typedef struct _MV_FRAME_OUT_INFO_
{
    unsigned short      nWidth;             ///< [OUT]  \~chinese 图像宽            \~english Image Width
    unsigned short      nHeight;            ///< [OUT]  \~chinese 图像高            \~english Image Height
    enum MvGvspPixelType    enPixelType;    ///< [OUT]  \~chinese 像素格式          \~english Pixel Type

    unsigned int        nFrameNum;          ///< [OUT]  \~chinese 帧号              \~english Frame Number
    unsigned int        nDevTimeStampHigh;  ///< [OUT]  \~chinese 时间戳高32位      \~english Timestamp high 32 bits
    unsigned int        nDevTimeStampLow;   ///< [OUT]  \~chinese 时间戳低32位      \~english Timestamp low 32 bits
    unsigned int        nReserved0;         ///< [OUT]  \~chinese 保留，8字节对齐   \~english Reserved, 8-byte aligned
    int64_t             nHostTimeStamp;     ///< [OUT]  \~chinese 主机生成的时间戳  \~english Host-generated timestamp

    unsigned int        nFrameLen;

    unsigned int        nLostPacket;  // 本帧丢包数
    unsigned int        nReserved[2];
}MV_FRAME_OUT_INFO;

/// \~chinese 保存图片参数            \~english Save image type
typedef struct _MV_SAVE_IMAGE_PARAM_T_
{
    unsigned char*      pData;              ///< [IN]   \~chinese 输入数据缓存      \~english Input Data Buffer
    unsigned int        nDataLen;           ///< [IN]   \~chinese 输入数据大小      \~english Input Data Size
    enum MvGvspPixelType    enPixelType;    ///< [IN]   \~chinese 输入像素格式      \~english Input Data Pixel Format
    unsigned short      nWidth;             ///< [IN]   \~chinese 图像宽            \~english Image Width
    unsigned short      nHeight;            ///< [IN]   \~chinese 图像高            \~english Image Height

    unsigned char*      pImageBuffer;       ///< [OUT]  \~chinese 输出图片缓存      \~english Output Image Buffer
    unsigned int        nImageLen;          ///< [OUT]  \~chinese 输出图片大小      \~english Output Image Size
    unsigned int        nBufferSize;        ///< [IN]   \~chinese 提供的输出缓冲区大小  \~english Output buffer size provided
    enum MV_SAVE_IAMGE_TYPE enImageType;    ///< [IN]   \~chinese 输出图片格式      \~english Output Image Format

}MV_SAVE_IMAGE_PARAM;

typedef struct _MV_IMAGE_BASIC_INFO_
{
    unsigned short      nWidthValue;
    unsigned short      nWidthMin;
    unsigned int        nWidthMax;
    unsigned int        nWidthInc;

    unsigned int        nHeightValue;
    unsigned int        nHeightMin;
    unsigned int        nHeightMax;
    unsigned int        nHeightInc;

    float               fFrameRateValue;
    float               fFrameRateMin;
    float               fFrameRateMax;

    unsigned int        enPixelType;        ///< [OUT]  \~chinese 当前的像素格式    \~english Current pixel format
    unsigned int        nSupportedPixelFmtNum;  ///< [OUT]  \~chinese 支持的像素格式种类    \~english Support pixel format
    unsigned int        enPixelList[MV_MAX_XML_SYMBOLIC_NUM];
    unsigned int        nReserved[8];

}MV_IMAGE_BASIC_INFO;


/// \~chinese 噪声特性类型    \~english Noise feature type
typedef enum _MV_CC_BAYER_NOISE_FEATURE_TYPE
{
    MV_CC_BAYER_NOISE_FEATURE_TYPE_INVALID = 0, ///<        \~chinese 无效值                        \~english Invalid
    MV_CC_BAYER_NOISE_FEATURE_TYPE_PROFILE = 1, ///<        \~chinese 噪声曲线                      \~english Noise curve
    MV_CC_BAYER_NOISE_FEATURE_TYPE_LEVEL   = 2, ///<        \~chinese 噪声水平                      \~english Noise level
    MV_CC_BAYER_NOISE_FEATURE_TYPE_DEFAULT = 1, ///<        \~chinese 默认值                        \~english Default

}MV_CC_BAYER_NOISE_FEATURE_TYPE;

/// \~chinese Bayer格式降噪特性信息    \~english Denoise profile info
typedef struct _MV_CC_BAYER_NOISE_PROFILE_INFO_T_
{
    unsigned int        nVersion;           ///<  \~chinese 版本                           \~english version
    MV_CC_BAYER_NOISE_FEATURE_TYPE enNoiseFeatureType;  ///<  \~chinese 噪声特性类型       \~english noise feature type
    enum MvGvspPixelType    enPixelType;    ///<  \~chinese 图像格式                       \~english image format
    int                 nNoiseLevel;        ///<  \~chinese 平均噪声水平                   \~english noise level
    unsigned int        nCurvePointNum;     ///<  \~chinese 曲线点数                       \~english curve point number
    int*                nNoiseCurve;        ///<  \~chinese 噪声曲线                       \~english noise curve
    int*                nLumCurve;          ///<  \~chinese 亮度曲线                       \~english luminance curve

    unsigned int        nRes[8];            ///<       \~chinese 预留                           \~english Reserved

}MV_CC_BAYER_NOISE_PROFILE_INFO;

/// \~chinese Bayer格式噪声估计参数    \~english Bayer noise estimate param
typedef struct _MV_CC_BAYER_NOISE_ESTIMATE_PARAM_T_
{
    unsigned int        nWidth;             ///< [IN]  \~chinese 图像宽(大于等于8)              \~english Width
    unsigned int        nHeight;            ///< [IN]  \~chinese 图像高(大于等于8)              \~english Height
    enum MvGvspPixelType    enPixelType;    ///< [IN]  \~chinese 像素格式                       \~english Pixel format

    unsigned char*      pSrcData;           ///< [IN]  \~chinese 输入数据缓存                   \~english Input data buffer
    unsigned int        nSrcDataLen;        ///< [IN]  \~chinese 输入数据大小                   \~english Input data size

    unsigned int        nNoiseThreshold;    ///< [IN]  \~chinese 噪声阈值(0-4095)               \~english Noise Threshold

    unsigned char*      pCurveBuf;          ///< [IN]  \~chinese 用于存储噪声曲线和亮度曲线（需要外部分配，缓存大小：4096 * sizeof(int) * 2）     \~english Buffer used to store noise and brightness curves, size:4096 * sizeof(int) * 2)
    MV_CC_BAYER_NOISE_PROFILE_INFO stNoiseProfile; ///< [OUT]  \~chinese 降噪特性信息               \~english Denoise profile

    unsigned int        nThreadNum;         ///< [IN]  \~chinese 线程数量，0表示算法库根据硬件自适应；1表示单线程（默认）；大于1表示线程数目      \~english Thread number, 0 means that the library is adaptive to the hardware, 1 means single thread(Default value), Greater than 1 indicates the number of threads

    unsigned int        nRes[8];            ///<       \~chinese 预留                           \~english Reserved

}MV_CC_BAYER_NOISE_ESTIMATE_PARAM;

/// \~chinese Bayer格式空域降噪参数    \~english Bayer spatial Denoise param
typedef struct _MV_CC_BAYER_SPATIAL_DENOISE_PARAM_T_
{
    unsigned int        nWidth;             ///< [IN]  \~chinese 图像宽(大于等于8)              \~english Width
    unsigned int        nHeight;            ///< [IN]  \~chinese 图像高(大于等于8)              \~english Height
    enum MvGvspPixelType    enPixelType;        ///< [IN]  \~chinese 像素格式                       \~english Pixel format

    unsigned char*      pSrcData;           ///< [IN]  \~chinese 输入数据缓存                   \~english Input data buffer
    unsigned int        nSrcDataLen;        ///< [IN]  \~chinese 输入数据大小                   \~english Input data size

    unsigned char*      pDstBuf;            ///< [OUT] \~chinese 输出降噪后的数据               \~english Output data buffer
    unsigned int        nDstBufSize;        ///< [IN]  \~chinese 提供的输出缓冲区大小           \~english Provided output buffer size
    unsigned int        nDstBufLen;         ///< [OUT] \~chinese 输出降噪后的数据长度           \~english Output data length

    MV_CC_BAYER_NOISE_PROFILE_INFO stNoiseProfile; ///< [IN]  \~chinese 降噪特性信息(来源于噪声估计)   \~english Denoise profile
    unsigned int        nDenoiseStrength;   ///< [IN]  \~chinese 降噪强度(0-100)                \~english nDenoise Strength   
    unsigned int        nSharpenStrength;   ///< [IN]  \~chinese 锐化强度(0-32)                 \~english Sharpen Strength
    unsigned int        nNoiseCorrect;      ///< [IN]  \~chinese 噪声校正系数(0-1280)           \~english Noise Correct  

    unsigned int        nThreadNum;         ///< [IN]  \~chinese 线程数量，0表示算法库根据硬件自适应；1表示单线程（默认）；大于1表示线程数目         \~english Thread number, 0 means that the library is adaptive to the hardware, 1 means single thread(Default value), Greater than 1 indicates the number of threads

    unsigned int        nRes[8];            ///<       \~chinese 预留                           \~english Reserved

}MV_CC_BAYER_SPATIAL_DENOISE_PARAM;

/// \~chinese 某个节点对应的子节点个数最大值    \~english The maximum number of child nodes corresponding to a node
#define MV_MAX_XML_NODE_NUM_C       128

/// \~chinese 节点名称字符串最大长度            \~english The maximum length of node name string
#define MV_MAX_XML_NODE_STRLEN_C    64

/// \~chinese 节点String值最大长度              \~english The maximum length of Node String
#define MV_MAX_XML_STRVALUE_STRLEN_C 64

/// \~chinese 节点描述字段最大长度              \~english The maximum length of the node description field
#define MV_MAX_XML_DISC_STRLEN_C    512

/// \~chinese 最多的单元数                      \~english The maximum number of units
#define MV_MAX_XML_ENTRY_NUM        10

/// \~chinese 父节点个数上限                    \~english The maximum number of parent nodes
#define MV_MAX_XML_PARENTS_NUM      8

/// \~chinese 每个已经实现单元的名称长度        \~english The length of the name of each unit that has been implemented
#define MV_MAX_XML_SYMBOLIC_STRLEN_C 64

enum MV_XML_Visibility
{
    V_Beginner      = 0,    ///< Always visible
    V_Expert        = 1,    ///< Visible for experts or Gurus
    V_Guru          = 2,    ///< Visible for Gurus
    V_Invisible     = 3,    ///< Not Visible
    V_Undefined     = 99    ///< Object is not yet initialized
};

/// \~chinese 单个节点基本属性 | en:Single Node Basic Attributes
typedef struct _MV_XML_NODE_FEATURE_
{
    enum MV_XML_InterfaceType   enType;                             ///< \~chinese 节点类型         \~english Node Type
    enum MV_XML_Visibility  enVisivility;                           ///< \~chinese 是否可见         \~english Is visibility
    char                strDescription[MV_MAX_XML_DISC_STRLEN_C];   ///< \~chinese 节点描述,目前暂不支持   \~english Node Description, NOT SUPPORT NOW
    char                strDisplayName[MV_MAX_XML_NODE_STRLEN_C];   ///< \~chinese 显示名称         \~english Display Name
    char                strName[MV_MAX_XML_NODE_STRLEN_C];          ///< \~chinese 节点名           \~english Node Name
    char                strToolTip[MV_MAX_XML_DISC_STRLEN_C];       ///< \~chinese 提示             \~english Notice

    unsigned int        nReserved[4];
}MV_XML_NODE_FEATURE;

/// \~chinese 节点列表 | en:Node List
typedef struct _MV_XML_NODES_LIST_
{
    unsigned int        nNodeNum;       ///< \~chinese 节点个数             \~english Node Number
    MV_XML_NODE_FEATURE stNodes[MV_MAX_XML_NODE_NUM_C];
}MV_XML_NODES_LIST;

typedef struct _MV_XML_FEATURE_Value_
{
    enum MV_XML_InterfaceType   enType;                             ///< \~chinese 节点类型         \~english Node Type
    char                strDescription[MV_MAX_XML_DISC_STRLEN_C];   ///< \~chinese 节点描述,目前暂不支持   \~english Node Description, NOT SUPPORT NOW
    char                strDisplayName[MV_MAX_XML_NODE_STRLEN_C];   ///< \~chinese 显示名称         \~english Display Name
    char                strName[MV_MAX_XML_NODE_STRLEN_C];          ///< \~chinese 节点名           \~english Node Name
    char                strToolTip[MV_MAX_XML_DISC_STRLEN_C];       ///< \~chinese 提示             \~english Notice
    unsigned int        nReserved[4];
}MV_XML_FEATURE_Value;

typedef struct _MV_XML_FEATURE_Base_
{
    enum MV_XML_AccessMode enAccessMode;                           ///< \~chinese 访问模式         \~english Access Mode
}MV_XML_FEATURE_Base;

typedef struct _MV_XML_FEATURE_Integer_
{
    char                strName[MV_MAX_XML_NODE_STRLEN_C];
    char                strDisplayName[MV_MAX_XML_NODE_STRLEN_C];
    char                strDescription[MV_MAX_XML_DISC_STRLEN_C];   ///< \~chinese 目前暂不支持     \~english NOT SUPPORT NOW
    char                strToolTip[MV_MAX_XML_DISC_STRLEN_C];

    enum MV_XML_Visibility  enVisivility;                           ///< \~chinese 是否可见         \~english Visible
    enum MV_XML_AccessMode  enAccessMode;                           ///< \~chinese 访问模式         \~english Access Mode
    int                 bIsLocked;                                  ///< \~chinese 是否锁定。0-否；1-是,目前暂不支持    \~english Locked. 0-NO; 1-YES, NOT SUPPORT NOW
    int64_t             nValue;                                     ///< \~chinese 当前值           \~english Current Value
    int64_t             nMinValue;                                  ///< \~chinese 最小值           \~english Min Value
    int64_t             nMaxValue;                                  ///< \~chinese 最大值           \~english Max Value
    int64_t             nIncrement;                                 ///< \~chinese 增量             \~english Increment

    unsigned int        nReserved[4];

}MV_XML_FEATURE_Integer;

typedef struct _MV_XML_FEATURE_Boolean_
{
    char                strName[MV_MAX_XML_NODE_STRLEN_C];
    char                strDisplayName[MV_MAX_XML_NODE_STRLEN_C];
    char                strDescription[MV_MAX_XML_DISC_STRLEN_C];   ///< \~chinese 目前暂不支持     \~english NOT SUPPORT NOW
    char                strToolTip[MV_MAX_XML_DISC_STRLEN_C];

    enum MV_XML_Visibility  enVisivility;                           ///< \~chinese 是否可见         \~english Visible
    enum MV_XML_AccessMode  enAccessMode;                           ///< \~chinese 访问模式         \~english Access Mode
    int                 bIsLocked;                                  ///< \~chinese 是否锁定。0-否；1-是,目前暂不支持    \~english Locked. 0-NO; 1-YES, NOT SUPPORT NOW
    bool                bValue;                                     ///< \~chinese 当前值           \~english Current Value

    unsigned int        nReserved[4];
}MV_XML_FEATURE_Boolean;

typedef struct _MV_XML_FEATURE_Command_
{
    char                strName[MV_MAX_XML_NODE_STRLEN_C];
    char                strDisplayName[MV_MAX_XML_NODE_STRLEN_C];
    char                strDescription[MV_MAX_XML_DISC_STRLEN_C];   ///< \~chinese 目前暂不支持     \~english NOT SUPPORT NOW
    char                strToolTip[MV_MAX_XML_DISC_STRLEN_C];

    enum MV_XML_Visibility  enVisivility;                           ///< \~chinese 是否可见         \~english Visible
    enum MV_XML_AccessMode  enAccessMode;                           ///< \~chinese 访问模式         \~english Access Mode
    int                 bIsLocked;                                  ///< \~chinese 是否锁定。0-否；1-是,目前暂不支持    \~english Locked. 0-NO; 1-YES, NOT SUPPORT NOW

    unsigned int        nReserved[4];
}MV_XML_FEATURE_Command;

typedef struct _MV_XML_FEATURE_Float_
{
    char                strName[MV_MAX_XML_NODE_STRLEN_C];
    char                strDisplayName[MV_MAX_XML_NODE_STRLEN_C];
    char                strDescription[MV_MAX_XML_DISC_STRLEN_C];   ///< \~chinese 目前暂不支持     \~english NOT SUPPORT NOW
    char                strToolTip[MV_MAX_XML_DISC_STRLEN_C];

    enum MV_XML_Visibility  enVisivility;                           ///< \~chinese 是否可见         \~english Visible
    enum MV_XML_AccessMode  enAccessMode;                           ///< \~chinese 访问模式         \~english Access Mode
    int                 bIsLocked;                                  ///< \~chinese 是否锁定。0-否；1-是,目前暂不支持    \~english Locked. 0-NO; 1-YES, NOT SUPPORT NOW
    double              dfValue;                                    ///< \~chinese 当前值           \~english Current Value
    double              dfMinValue;                                 ///< \~chinese 最小值           \~english Min Value
    double              dfMaxValue;                                 ///< \~chinese 最大值           \~english Max Value
    double              dfIncrement;                                ///< \~chinese 增量             \~english Increment

    unsigned int        nReserved[4];
}MV_XML_FEATURE_Float;

typedef struct _MV_XML_FEATURE_String_
{
    char                strName[MV_MAX_XML_NODE_STRLEN_C];
    char                strDisplayName[MV_MAX_XML_NODE_STRLEN_C];
    char                strDescription[MV_MAX_XML_DISC_STRLEN_C];   ///< \~chinese 目前暂不支持     \~english NOT SUPPORT NOW
    char                strToolTip[MV_MAX_XML_DISC_STRLEN_C];

    enum MV_XML_Visibility  enVisivility;                           ///< \~chinese 是否可见         \~english Visible
    enum MV_XML_AccessMode  enAccessMode;                           ///< \~chinese 访问模式         \~english Access Mode
    int                 bIsLocked;                                  ///< \~chinese 是否锁定。0-否；1-是,目前暂不支持    \~english Locked. 0-NO; 1-YES, NOT SUPPORT NOW
    char                strValue[MV_MAX_XML_STRVALUE_STRLEN_C];     ///< \~chinese 当前值           \~english Current Value

    unsigned int        nReserved[4];
}MV_XML_FEATURE_String;

typedef struct _MV_XML_FEATURE_Register_
{
    char                strName[MV_MAX_XML_NODE_STRLEN_C];
    char                strDisplayName[MV_MAX_XML_NODE_STRLEN_C];
    char                strDescription[MV_MAX_XML_DISC_STRLEN_C];   ///< \~chinese 目前暂不支持     \~english NOT SUPPORT NOW
    char                strToolTip[MV_MAX_XML_DISC_STRLEN_C];

    enum MV_XML_Visibility  enVisivility;                           ///< \~chinese 是否可见         \~english Visible
    enum MV_XML_AccessMode  enAccessMode;                           ///< \~chinese 访问模式         \~english Access Mode
    int                 bIsLocked;                                  ///< \~chinese 是否锁定。0-否；1-是,目前暂不支持    \~english Locked. 0-NO; 1-YES, NOT SUPPORT NOW
    int64_t             nAddrValue;                                 ///< \~chinese 当前值           \~english Current Value

    unsigned int        nReserved[4];
}MV_XML_FEATURE_Register;

typedef struct _MV_XML_FEATURE_Category_
{
    char                strDescription[MV_MAX_XML_DISC_STRLEN_C];   ///< \~chinese 节点描述 目前暂不支持    \~english Node Description, NOT SUPPORT NOW
    char                strDisplayName[MV_MAX_XML_NODE_STRLEN_C];   ///< \~chinese 显示名称         \~english Display Name
    char                strName[MV_MAX_XML_NODE_STRLEN_C];          ///< \~chinese 节点名           \~english Node Name
    char                strToolTip[MV_MAX_XML_DISC_STRLEN_C];       ///< \~chinese 提示             \~english Notice

    enum MV_XML_Visibility  enVisivility;                           ///< \~chinese 是否可见         \~english Visible

    unsigned int        nReserved[4];
}MV_XML_FEATURE_Category;

typedef struct _MV_XML_FEATURE_EnumEntry_
{
    char                strName[MV_MAX_XML_NODE_STRLEN_C];
    char                strDisplayName[MV_MAX_XML_NODE_STRLEN_C];
    char                strDescription[MV_MAX_XML_DISC_STRLEN_C];   ///< \~chinese 目前暂不支持     \~english NOT SUPPORT NOW
    char                strToolTip[MV_MAX_XML_DISC_STRLEN_C];
    int                 bIsImplemented;
    int                 nParentsNum;
    MV_XML_NODE_FEATURE stParentsList[MV_MAX_XML_PARENTS_NUM];

    enum MV_XML_Visibility  enVisivility;                           ///< \~chinese 是否可见         \~english Visible
    int64_t             nValue;                                     ///< \~chinese 当前值           \~english Current Value
    enum MV_XML_AccessMode  enAccessMode;                           ///< \~chinese 访问模式         \~english Access Mode
    int                 bIsLocked;                                  ///< \~chinese 是否锁定。0-否；1-是,目前暂不支持    \~english Locked. 0-NO; 1-YES, NOT SUPPORT NOW
    int                 nReserved[8];

}MV_XML_FEATURE_EnumEntry;

typedef struct _MV_XML_FEATURE_Enumeration_
{
    enum MV_XML_Visibility  enVisivility;                           ///< \~chinese 是否可见         \~english Visible
    char                strDescription[MV_MAX_XML_DISC_STRLEN_C];   ///< \~chinese 节点描述 目前暂不支持    \~english Node Description, NOT SUPPORT NOW
    char                strDisplayName[MV_MAX_XML_NODE_STRLEN_C];   ///< \~chinese 显示名称         \~english Display Name
    char                strName[MV_MAX_XML_NODE_STRLEN_C];          ///< \~chinese 节点名           \~english Node Name
    char                strToolTip[MV_MAX_XML_DISC_STRLEN_C];       ///< \~chinese 提示             \~english Notice

    int                 nSymbolicNum;                               ///< \~chinese ymbolic数        \~english Symbolic Number
    char                strCurrentSymbolic[MV_MAX_XML_SYMBOLIC_STRLEN_C];///< \~chinese 当前Symbolic索引    \~english Current Symbolic Index
    char                strSymbolic[MV_MAX_XML_SYMBOLIC_NUM][MV_MAX_XML_SYMBOLIC_STRLEN_C];
    enum MV_XML_AccessMode   enAccessMode;                          ////< \~chinese 访问模式        \~english Access Mode
    int                 bIsLocked;                                  ///< \~chinese 是否锁定。0-否；1-是,目前暂不支持    \~english Locked. 0-NO; 1-YES, NOT SUPPORT NOW
    int64_t             nValue;                                     ///< \~chinese 当前值           \~english Current Value

    unsigned int        nReserved[4];
}MV_XML_FEATURE_Enumeration;

typedef struct _MV_XML_FEATURE_Port_
{
    enum MV_XML_Visibility  enVisivility;                           ///< \~chinese 是否可见         \~english Visible
    char                strDescription[MV_MAX_XML_DISC_STRLEN_C];   ///< \~chinese 节点描述,目前暂不支持    \~english Node Description, NOT SUPPORT NOW
    char                strDisplayName[MV_MAX_XML_NODE_STRLEN_C];   ///< \~chinese 显示名称         \~english Display Name
    char                strName[MV_MAX_XML_NODE_STRLEN_C];          ///< \~chinese 节点名           \~english Node Name
    char                strToolTip[MV_MAX_XML_DISC_STRLEN_C];       ///< \~chinese 提示             \~english Notice

    enum MV_XML_AccessMode  enAccessMode;                           ///< \~chinese 访问模式         \~english Access Mode
    int                 bIsLocked;                                  ///< \~chinese 是否锁定。0-否；1-是,目前暂不支持    \~english Locked. 0-NO; 1-YES, NOT SUPPORT NOW

    unsigned int        nReserved[4];
}MV_XML_FEATURE_Port;

typedef struct _MV_XML_CAMERA_FEATURE_
{
    enum MV_XML_InterfaceType    enType;
    union
    {
        MV_XML_FEATURE_Integer      stIntegerFeature;
        MV_XML_FEATURE_Float        stFloatFeature;
        MV_XML_FEATURE_Enumeration  stEnumerationFeature;
        MV_XML_FEATURE_String       stStringFeature;
    }SpecialFeature;

}MV_XML_CAMERA_FEATURE;

#endif /* _MV_OBSOLETE_CAM_PARAMS_H_ */
