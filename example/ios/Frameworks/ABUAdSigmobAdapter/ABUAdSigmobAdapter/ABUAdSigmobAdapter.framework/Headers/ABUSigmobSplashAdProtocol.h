//
//  ABUSigmobSplashAdProtocol.h
//  ABUAdSDK
//
//  Created by CHAORS on 2021/9/23.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "ABUSigmobCommonProtocol.h"


NS_ASSUME_NONNULL_BEGIN
#pragma mark sigmob 4.1.0 废弃
@protocol ABUSigmob_WindSplashAdDelegate;
@protocol ABUSigmob_WindSplashAd <NSObject>

@property (nonatomic,weak) id<ABUSigmob_WindSplashAdDelegate> delegate;

/**
 *  拉取广告超时时间，默认为3秒
 *  详解：拉取广告超时时间，开发者调用loadAd方法以后会立即展示app的启动图，然后在该超时时间内，如果广告拉
 *  取成功，则立马展示开屏广告，否则放弃此次广告展示机会。
 */
@property (nonatomic, assign) int fetchDelay;

/**
 *  取消关闭动画 default = NO
 */
@property (nonatomic, assign) BOOL cancelClosedAnimate;


/**
 *  开屏广告的背景色
 *  可以设置开屏图片来作为开屏加载时的默认图片
 */
@property (nonatomic, copy) UIColor *backgroundColor;

@property (nonatomic,strong, readonly) NSString *placementId;

@property (nonatomic,strong) NSString *userId;



/**
 * 返回广告是否可展示
 * 对于并行请求，在调用showAdInWindow前时需判断下
 * @return 当广告已经加载完成且未曝光时，为YES，否则为NO
 */
- (BOOL)isAdReady;


/**
 初始化splash ad对象（如果是加载后自动播放，请使用该构造函数）
 @param placementId 广告位ID
 */
- (instancetype)initWithPlacementId:(NSString *)placementId;

/**
 *  广告发起请求并展示在Window中
 *  详解：[可选]发起拉取广告请求,并将获取的广告以全屏形式展示在传入的Window参数中
 */
-(void)loadAdAndShow;


/**
 *  广告发起请求并展示在Window中, 同时在屏幕底部设置应用自身的Logo页面或是自定义View
 *  详解：[可选]发起拉取广告请求,并将获取的广告以半屏形式展示在传入的Window的上半部，剩余部分展示传入的bottomView
 *       请注意bottomView需设置好宽高，所占的空间不能过大，并保证广告界面的高度大于360
 *  @param bottomView 自定义底部View，可以在此View中设置应用Logo
 *
 */
-(void)loadAdAndShowWithBottomView:(UIView *)bottomView;



/**
 *  广告发起请求并展示在Window中, 同时在屏幕底部设置应用自身的Logo页面
 *  详解：[logo会自动读取应用图标]
 *
 @param title 设置标题
 @param description 设置描述信息
 */
- (void)loadADAndShowWithTitle:(NSString *)title description:(NSString *)description;

////////////////////////////////////////////////////////////////////////////////////////////////////


/**
 初始化splash ad对象（如果是加载和播放分开处理，请使用该构造函数）
 @param placementId 广告位ID
 @param extra 各个平台需要的扩展参数，可以根据聚合的平台设置，
 详细参考在线文档：http://docs.sigmob.cn/#/sdk/SDK%E6%8E%A5%E5%85%A5/ios/
 extra: 中必填参数：kSMSplashExtraRootViewController & kSMSplashExtraAdSize
 extra参数介绍：https://support.sigmob.com/#/sdk%E9%9B%86%E6%88%90/iOS/%E5%B9%BF%E5%91%8A%E5%BD%A2%E5%BC%8F%E5%8F%8A%E6%8E%A5%E5%85%A5/%E5%BC%80%E5%B1%8F%E5%B9%BF%E5%91%8A/?id=extra-%e5%8f%82%e6%95%b0%e4%bb%8b%e7%bb%8d
 */
- (instancetype)initWithPlacementId:(NSString *)placementId
                              extra:(NSDictionary *)extra;

/**
 *  发起拉取广告请求，只拉取不展示
 *  详解：广告素材及广告图片拉取成功后会回调onSplashAdDidLoad方法，当拉取失败时会回调onSplashAdFailToPresent方法
 */
- (void)loadAd;

/**
 *  展示广告，调用此方法前需调用isAdValid方法判断广告素材是否有效
 *  详解：广告展示成功时会回调onSplashAdSuccessPresentScreen方法，展示失败时会回调onSplashAdFailToPresent方法
 */
- (void)showAdInWindow:(UIWindow *)window withBottomView:(UIView *)bottomView;


/**
 *  广告发起请求并展示在Window中, 同时在屏幕底部设置应用自身的Logo页面
 *  详解：[logo会自动读取应用图标]，请中高度位100，宽度为屏幕宽度
 *
 @param window 容器
 @param title 设置标题
 @param desc 设置描述信息
 */
- (void)showAdInWindow:(UIWindow *)window title:(NSString *)title desc:(NSString *)desc;

@end

typedef NSObject<ABUSigmob_WindSplashAd> WindSplashAd;
@protocol ABUSigmob_WindSplashAdDelegate <NSObject>

@optional
/**
 *  开屏广告素材加载成功
 */
- (void)onSplashAdDidLoad:(WindSplashAd *)splashAd;

/**
 *  开屏广告展示失败
 */
-(void)onSplashAdLoadFail:(WindSplashAd *)splashAd error:(NSError *)error;

/**
 *  开屏广告成功展示
 */
-(void)onSplashAdSuccessPresentScreen:(WindSplashAd *)splashAd;

/**
 *  开屏广告展示失败
 */
-(void)onSplashAdFailToPresent:(WindSplashAd *)splashAd withError:(NSError *)error;


/**
 *  开屏广告点击回调
 */
- (void)onSplashAdClicked:(WindSplashAd *)splashAd;


/**
 *  开屏广告点击跳过
 */
- (void)onSplashAdSkiped:(WindSplashAd *)splashAd;

/**
 *  开屏广告将要关闭回调
 */
- (void)onSplashAdWillClosed:(WindSplashAd *)splashAd;

/**
 *  开屏广告关闭回调
 */
- (void)onSplashAdClosed:(WindSplashAd *)splashAd;

@end
#pragma mark sigmob 4.1.0 废弃

// v3600
@protocol ABUSigmob_WindSplashAdViewDelegate;
@protocol ABUSigmob_WindSplashAdView <NSObject>

@property (nonatomic,weak) id<ABUSigmob_WindSplashAdViewDelegate> delegate;

@property (nonatomic,strong, readonly) NSString *placementId;

@property (nonatomic, weak) UIViewController *rootViewController;

/**
 *  拉取广告超时时间，默认为5秒
 */
@property (nonatomic, assign) int fetchDelay;

/**
 广告是否有效
 广告加载后存在一定的时效性，在展示前请先验证adValid
 */
@property (nonatomic, getter=isAdValid, readonly) BOOL adValid;


- (instancetype)initWithRequest:(WindAdRequest *)request;

/// load ad data
- (void)loadAdData;


/**
*  Called when load ad data
*
*  @param bidToken    - the token from bid request within Sigmob Ad Server
*/
- (void)loadAdDataWithBidToken:(NSString *)bidToken;

@end
typedef UIView <ABUSigmob_WindSplashAdView> WindSplashAdView;

@protocol ABUSigmob_WindSplashAdViewDelegate <NSObject>
@optional
/**
 *  开屏广告素材加载成功
 */
- (void)onSplashAdDidLoad:(WindSplashAdView *)splashAdView;

/**
 *  开屏广告展示失败
 */
-(void)onSplashAdLoadFail:(WindSplashAdView *)splashAdView error:(NSError *)error;

/**
 *  开屏广告成功展示
 */
-(void)onSplashAdSuccessPresentScreen:(WindSplashAdView *)splashAdView;

/**
 *  开屏广告展示失败
 */
-(void)onSplashAdFailToPresent:(WindSplashAdView *)splashAdView withError:(NSError *)error;


/**
 *  开屏广告点击回调
 */
- (void)onSplashAdClicked:(WindSplashAdView *)splashAdView;


/**
 *  开屏广告点击跳过
 */
- (void)onSplashAdSkiped:(WindSplashAdView *)splashAdView;

/**
 *  开屏广告关闭回调
 */
- (void)onSplashAdClosed:(WindSplashAdView *)splashAdView;

@end



NS_ASSUME_NONNULL_END
