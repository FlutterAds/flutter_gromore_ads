//
//  ABUNativeAd.h
//  ABUAdSDK
//
//  Created by bytedance on 2021/6/8.
//

#import "ABUBaseAd.h"
#import "ABUSize.h"
#import "ABUNativeAdView.h"

NS_ASSUME_NONNULL_BEGIN

/// Native广告配置协议
@protocol ABUNativeAdSlot <NSObject>
@required

/// 必要，广告位ID
@property (nonatomic, copy) NSString *ID;

@optional

/// 是否获取模板广告，默认为NO，优先以平台配置为准
@property (nonatomic, assign) BOOL getExpressAdIfCan;

/// 图片大小，包括视频媒体的大小设定
@property (nonatomic, strong) ABUSize *imgSize;

/// 同imgSize
@property (nonatomic, assign) CGSize imageOrVideoSize;

/// 广告视图的尺寸，请勿设置为0
@property (nonatomic, assign) CGSize adSize;

@end

#define ABUAdSlotPositionFeed 0;

/// 旧版本广告配置类
@interface ABUAdUnit : NSObject <ABUNativeAdSlot>

/// 旧版本兼容字段，无需设置
@property (nonatomic, assign) ABUAdSlotAdType AdType ABU_DEPRECATED_MSG_ATTRIBUTE("接口即将废弃，无需设置");

/// 旧版本兼容字段，无需设置
@property (nonatomic, assign) ABUAdSlotPosition position ABU_DEPRECATED_MSG_ATTRIBUTE("接口即将废弃，无需设置");

/// 旧版本兼容字段，无需设置
@property (nonatomic, assign) BOOL isSupportDeepLink ABU_DEPRECATED_MSG_ATTRIBUTE("接口即将废弃，无需设置");

@end

@class ABUNativeAdsManager;

/// Native 广告回调协议
@protocol ABUNativeAdsManagerDelegate <NSObject>

@optional

/// Native 广告加载成功回调
/// @param adsManager 广告管理对象
/// @param nativeAdViewArray 广告视图，GroMore包装视图对象组，包括模板广告和自渲染广告
- (void)nativeAdsManagerSuccessToLoad:(ABUNativeAdsManager *_Nonnull)adsManager nativeAds:(NSArray<ABUNativeAdView *> *_Nullable)nativeAdViewArray;

/// Native 广告加载失败回调
/// @param adsManager 广告管理对象
/// @param error  加载出错信息
- (void)nativeAdsManager:(ABUNativeAdsManager *_Nonnull)adsManager didFailWithError:(NSError *_Nullable)error;

/// 暂不开放使用
- (void)nativeAdsManager:(ABUNativeAdsManager *_Nonnull)adsManager didWaitingBiddingResultWithParameters:(NSDictionary *)parameters andResumeHandler:(void(^)(NSDictionary *_Nullable data, NSError *_Nullable error))handler;

/// 暂不开放使用
- (void)nativeAdsManagerDidFinishLoadAdnAd:(ABUNativeAdsManager *_Nonnull)adsManager nativeAd:(ABUNativeAdView *_Nullable)nativeAd error:(NSError *_Nullable)error;

@end

/// Native广告加载类
@interface ABUNativeAdsManager : ABUBaseAd

/// 广告构建方法，开发者可使用'ABUAdUnit'类创建协议对象，也可自行创建类实现协议
/// @param slot 广告位ID
- (instancetype)initWithSlot:(id<ABUNativeAdSlot>)slot;

/// 快速广告构建方法
/// @param unitID 广告位ID
/// @param adSize 广告视图大小
- (instancetype)initWithAdUnitID:(NSString *)unitID adSize:(CGSize)adSize;

/// 是否使用模板广告，只对支持模板广告的第三方SDK有效，默认为NO，仅在广告加载前设置有效，优先以平台配置为准
@property (nonatomic, assign) BOOL getExpressAdIfCan;

/// 是否使用GDT express 2.0，对GDT（ ≥ 4.11.9）有效，默认为NO，仅在广告加载前设置有效，优先以平台配置为准
@property (nonatomic, assign) BOOL useExpress2IfCanForGDT ABU_DEPRECATED_MSG_ATTRIBUTE("接口即将废弃，在SDK V2900以上结合GDT V4.12.80以上 Gdt的原生模板广告在客户端无需区分2.0和1.0");

/// 图片大小，包括视频媒体的大小设定
@property (nonatomic, assign) CGSize imageOrVideoSize;

/// 广告视图的尺寸，请勿设置为0
@property (nonatomic, assign) CGSize adSize;

/// 是否静音播放视频，是否真实静音由adapter确定，默认为NO，仅在广告加载前设置有效，优先以平台配置为准
@property (nonatomic, assign) BOOL startMutedIfCan;

/// 广告代理对象
@property (nonatomic, weak) id<ABUNativeAdsManagerDelegate> delegate;

/// 必要，设置广告详情跳转控制器
@property (nonatomic, weak) UIViewController *rootViewController;

/// 加载广告方法
/// @param count 加载广告的数量，建议单次不超过3个，优先以平台上配置为准
- (void)loadAdDataWithCount:(NSUInteger)count;

- (void)loadAdData;

/// 不再使用加载成功后回调的视图对象组时，可调用该方法释放占用的内存
- (void)destory;

@end

NS_ASSUME_NONNULL_END
