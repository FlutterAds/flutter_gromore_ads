//
// Created by bytedance on 2021/7/5.
//

#import <Foundation/Foundation.h>
#import "ABUAdSDKConst.h"

@class ABUImage;

typedef NS_ENUM (NSInteger, ABUMediatedNativeAdCallToType) {
    ABUMediatedNativeAdCallToTypeUnknown        = 0,
    ABUMediatedNativeAdCallToTypeNone           = 1,  // pure ad display
    ABUMediatedNativeAdCallToTypeURL            = 2,  // open the webpage using a browser
    ABUMediatedNativeAdCallToTypePage           = 3,  // open the webpage within the app
    ABUMediatedNativeAdCallToTypeDownload       = 4,  // download the app
    ABUMediatedNativeAdCallToTypePhone          = 5,  // make a call
    ABUMediatedNativeAdCallToTypeMessage        = 6,  // send messages
    ABUMediatedNativeAdCallToTypeEmail          = 7,  // send email
    ABUMediatedNativeAdCallToTypeVideoAdDetail  = 8,   // video ad details page
    ABUMediatedNativeAdCallToTypeOthers         = 100 //其他广告sdk返回的类型
};

typedef NS_ENUM (NSInteger, ABUMediatedNativeAdMode) {
    ABUMediatedNativeAdModeUnknown          = 00, // 未知
    ABUMediatedNativeAdModeSmallImage       = 02, // 水平小图样式
    ABUMediatedNativeAdModeLargeImage       = 03, // 水平大图样式
    ABUMediatedNativeAdModeGroupImage       = 04, // 水平组图样式
    ABUMediatedNativeAdModeLandscapeVideo   = 05, // 水平视频样式
    ABUMediatedNativeAdModePortraitVideo    = 15, // 垂直视频样式
    ABUMediatedNativeAdModePortraitImage    = 16, // 垂直图片样式
    // 兼容
    ABUFeedADModeSmallImage                 = 02, // ABUMediatedNativeAdModeSmallImage,
    ABUFeedADModeLargeImage                 = 03, // ABUMediatedNativeAdModeLargeImage,
    ABUFeedADModeGroupImage                 = 04, // ABUMediatedNativeAdModeGroupImage,
    ABUFeedVideoAdModeImage                 = 05, // ABUMediatedNativeAdModeLandscapeVideo,
    ABUFeedVideoAdModePortrait              = 15, // ABUMediatedNativeAdModePortraitVideo,
    ABUFeedADModeImagePortrait              = 16, // ABUMediatedNativeAdModePortraitImage,
};

typedef ABUMediatedNativeAdMode ABUFeedADMode;

@protocol ABUMediatedNativeAdData;
@class ABUDislikeReason;

typedef NSObject<ABUMediatedNativeAdData> ABUMaterialMeta;

/// 媒体native ad数据协议，配合ABUMediatedNativeAdViewCreator使用
@protocol ABUMediatedNativeAdData <NSObject>

/// 广告支持的跳转类型
@property (nonatomic, assign, readonly) ABUMediatedNativeAdCallToType callToType;

/// 物料图片集，如果图片有宽高，请尽量配置width和height
@property (nonatomic, copy, readonly, nullable) NSArray<ABUImage *> *imageList;

/// app类型广告的广告商app图标，如果图标有宽高，请尽量配置width和height
@property (nonatomic, strong, readonly, nullable) ABUImage *icon;

/// 广告adn的logo，如果logo有宽高，请尽量配置width和height
@property (nonatomic, strong, readonly, nullable) ABUImage *adLogo;

/// 广告标题
@property (nonatomic, copy, readonly, nullable) NSString *adTitle;

/// 广告详情描述
@property (nonatomic, copy, readonly, nullable) NSString *adDescription;

/// 应用来源、市场，例如'App Store'
@property (nonatomic, copy, readonly, nullable) NSString *source;

/// 按钮文案，例如'下载/安装'
@property (nonatomic, copy, readonly, nullable) NSString *buttonText;

/// 图片/视频模式
@property (nonatomic, assign, readonly) ABUMediatedNativeAdMode imageMode;

/// app评分，区间为1-5，如果没有值返回-1
@property (nonatomic, assign, readonly) NSInteger score;

/// 评论数量，如果没有值返回-1
@property (nonatomic, assign, readonly) NSInteger commentNum;

/// 广告安装包体大小，单位KB，如果没有值返回-1
@property (nonatomic, assign, readonly) NSInteger appSize;

/// 视频时长，单位秒，如果没有值返回0
@property (nonatomic, assign, readonly) NSInteger videoDuration;

/// 视频纵横比(width/height)，如果没有值或者异常返回0
@property (nonatomic, assign, readonly) CGFloat videoAspectRatio;

/// 媒体扩展数据
@property (nonatomic, copy, readonly, nullable) NSDictionary *mediaExt;

/// app购买价格，例如'免费'，没有则为nil
@property (nonatomic, strong, readonly, nullable) NSString *appPrice;

/// 广告商标识，广告商的名称或者链接
@property (nonatomic, copy, readonly, nullable) NSString *advertiser;

/// 品牌名称，若广告返回中无品牌名称则为空
@property (copy, nonatomic, readonly, nullable) NSString *brandName;

/// ADN提供的不喜欢广告的原因，可能为空
@property (nonatomic, copy, readonly, nullable) NSArray<ABUDislikeReason *> *dislikeReasons;

/// ADN提供的视频类型广告的资源路径，部分ADN需要申请白名单，可能为空
@property (nonatomic, copy, readonly, nullable) NSString *videoUrl;

@end

