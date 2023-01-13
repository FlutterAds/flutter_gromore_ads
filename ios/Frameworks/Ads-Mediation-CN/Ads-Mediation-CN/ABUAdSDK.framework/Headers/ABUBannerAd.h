//
//  ABUNewBannerAd.h
//  ABUAdSDK
//
//  Created by Makaiwen on 2021/5/28.
//

#import "ABUBaseAd.h"
#import "ABUAdSDKConst.h"
#import "ABUCanvasView.h"

NS_ASSUME_NONNULL_BEGIN
    
@class ABUBannerAd, ABUDictionary;

/// banner广告代理协议
@protocol ABUBannerAdDelegate <NSObject>
@optional

/// banner广告加载成功回调
/// @param bannerAd 广告操作对象
/// @param bannerView 广告视图
- (void)bannerAdDidLoad:(ABUBannerAd *)bannerAd bannerView:(UIView *)bannerView;

/// 广告加载失败回调
/// @param bannerAd 广告操作对象
/// @param error 错误信息
- (void)bannerAd:(ABUBannerAd *)bannerAd didLoadFailWithError:(NSError *_Nullable)error;

/// 广告加载成功后为「混用的信息流自渲染广告」时会触发该回调，提供给开发者自渲染的时机
/// @param bannerAd 广告操作对象
/// @param canvasView 携带物料的画布，需要对其内部提供的物料及控件做布局及设置UI
/// @warning 轮播开启时，每次轮播到自渲染广告均会触发该回调，并且canvasView为其他回调中bannerView的子控件
- (void)bannerAdNeedLayoutUI:(ABUBannerAd *)bannerAd canvasView:(ABUCanvasView *)canvasView;

/// 广告展示回调
/// @param bannerAd 广告操作对象
/// @param bannerView 广告视图
- (void)bannerAdDidBecomeVisible:(ABUBannerAd *)bannerAd bannerView:(UIView *)bannerView;

/// 即将弹出广告详情页
/// @param ABUBannerAd 广告操作对象
/// @param bannerView 广告视图
- (void)bannerAdWillPresentFullScreenModal:(ABUBannerAd *)ABUBannerAd bannerView:(UIView *)bannerView;

/// 详情广告页将要关闭
/// @param ABUBannerAd 广告操作对象
/// @param bannerView 广告视图
- (void)bannerAdWillDismissFullScreenModal:(ABUBannerAd *)ABUBannerAd bannerView:(UIView *)bannerView;

/// 广告点击事件回调
/// @param ABUBannerAd 广告操作对象
/// @param bannerView 广告视图
- (void)bannerAdDidClick:(ABUBannerAd *)ABUBannerAd bannerView:(UIView *)bannerView;

/// 广告关闭回调
/// @param ABUBannerAd 广告操作对象
/// @param bannerView 广告视图
/// @param filterWords 不喜欢广告的原因，由adapter开发者配置，可能为空
- (void)bannerAdDidClosed:(ABUBannerAd *)ABUBannerAd bannerView:(UIView *)bannerView dislikeWithReason:(NSArray<NSDictionary *> *_Nullable)filterWords;

@end

/// banner广告操作类
@interface ABUBannerAd : ABUBaseAd

/// banner广告操作对象构建
/// @param adUnitID 广告位ID
/// @param rootViewController 页面跳转控制器
/// @param adSize 广告尺寸
- (instancetype _Nonnull)initWithAdUnitID:(NSString *_Nonnull)adUnitID
                       rootViewController:(UIViewController *_Nonnull)rootViewController
                                   adSize:(CGSize)adSize;

/// 广告代理回调对象
@property (nonatomic, weak) id<ABUBannerAdDelegate> delegate;

/// 广告尺寸，构造方法中传递的尺寸值
@property (nonatomic, assign, readonly) CGSize adSize;

/// 实际的自动轮播定时间隔，有效值在30-120之间
@property (nonatomic, assign, readonly) NSInteger autoRefreshTime __attribute__((unavailable("This attribute is invalid, get the value of refreshTime")));

/// 平台设置的Banner轮播时间间隔, 范围[10, 180], 其他值按0处理, 默认为0，单位秒
@property (nonatomic, assign, readonly) NSInteger refreshTime;

/// 是否已经准备广告展示，理论上在广告加载回调后即为YES，但受一些因素的影响（例如广告失效），可能为NO。建议在广告展示前调用该方法进行是否可以展示
@property (nonatomic, assign, readonly) BOOL isReady;

/// 返回显示广告对应的披露信息，当没有权限访问时Ecpm会返回'-3'
- (nullable ABURitInfo *)getShowEcpmInfo;

/// 填充后可调用, 返回广告缓存池内所有信息；nil为无权限
- (NSArray<ABURitInfo *> *)cacheRitList;

/// 广告的扩展信息，可能为nil
- (ABUDictionary *_Nullable)extraData;

/// 填充后可调用，获取广告中的extra信息。目前只支持穿山甲，并且只支持获取coupon, live_room, product信息。
- (nullable NSDictionary *)getMediaExtraInfo;

/// 不再使用加载成功后回调的view时，可调用该方法释放占用的内存
- (void)destory;

@end


/// banner广告位下混用了信息流代码位
@interface ABUBannerAd (mixture)

/// 是否使用模板广告，只对支持模板广告的第三方SDK有效，默认为NO，仅在广告加载前设置有效，优先以平台配置为准
@property (nonatomic, assign) BOOL getExpressAdIfCan;

/// 图片大小，包括视频媒体的大小设定
@property (nonatomic, assign) CGSize imageOrVideoSize;

/// 是否静音播放视频，是否真实静音由adapter确定，默认为YES，仅在广告加载前设置有效，优先以平台配置为准
@property (nonatomic, assign) BOOL startMutedIfCan;

@end

NS_ASSUME_NONNULL_END
