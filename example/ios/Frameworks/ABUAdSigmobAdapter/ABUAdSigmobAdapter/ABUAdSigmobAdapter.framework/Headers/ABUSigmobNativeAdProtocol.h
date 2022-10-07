//
//  ABUSigmobNativeAdProtocol.h
//  ABUAdSDK
//
//  Created by heyinyin on 2021/10/21.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, ABUSigmob_WindFeedADMode) {
    WindFeedADModeSmallImage = 2,
    WindFeedADModeLargeImage = 3,
    WindFeedADModeGroupImage = 4,
    WindFeedAdModeVideo = 14,
    WindFeedAdModeVideoPortrait = 15,
    WindFeedAdModeVideoLandSpace = 16,
};

@protocol ABUSigmob_WindDislikeWords <NSObject>

@property (nonatomic, copy, readonly) NSString *dislikeId;
@property (nonatomic, copy, readonly) NSString *name;
@property (nonatomic, copy, readonly) NSArray<id<ABUSigmob_WindDislikeWords>> *options;// v3600
@end

typedef NSObject<ABUSigmob_WindDislikeWords> WindDislikeWords;

@protocol ABUSigmob_WindNativeAdDelegate <NSObject>

@end
typedef id<ABUSigmob_WindNativeAdDelegate> WindNativeAdDelegate;
/// 分界线

@protocol ABUSigmob_WindNativeAd <NSObject>
/// Typed access to the ad title.
@property (nonatomic, copy, readonly) NSString *title;

/// Typed access to the body text, usually a longer description of the ad.
@property (nonatomic, copy, readonly) NSString *desc;

/// Typed access to the ad icon.
@property (nonatomic, copy, readonly) NSString *iconUrl;

/// Typed access to the call to action phrase of the ad.
@property (nonatomic, copy, readonly) NSString *callToAction;

/// Typed access to the ad star rating.
@property (nonatomic, assign, readonly) double rating;

@property (nonatomic, assign, readonly) ABUSigmob_WindFeedADMode feedADMode;

@end

typedef NSObject<ABUSigmob_WindNativeAd> WindNativeAd;


@protocol ABUSigmob_WindNativeAdViewDelegate;
@protocol ABUSigmob_WindNativeAdView <NSObject>

@property (nonatomic, strong, readonly) WindNativeAd *nativeAd;


/**
 广告 View 时间回调对象
 */
@property (nonatomic, weak) id<ABUSigmob_WindNativeAdViewDelegate> delegate;

/*
 *  viewControllerForPresentingModalView
 *  详解：开发者需传入用来弹出目标页的ViewController，一般为当前ViewController
 */
@property (nonatomic, weak) UIViewController *viewController;


/**
 视频组件
 */
@property (nonatomic, strong, readonly) WindMediaView *mediaView;// 3600

/**
 广告平台logo组件
 */
@property (nonatomic, strong, readonly) UIView *logoView;

/**
 dislike组件
 */
@property (nonatomic, strong, readonly) UIButton *dislikeButton;

// v3600
#pragma mark sigmob 4.1.0 废弃
/**
 单图广告对应的图片组件
 */
@property (nonatomic, strong, readonly) UIImageView *mainImageView;

/**
 3张小图对应的图片组建leftImageView、midImageView、rightImageView
 */
@property (nonatomic, strong, readonly) UIImageView *leftImageView;
@property (nonatomic, strong, readonly) UIImageView *midImageView;
@property (nonatomic, strong, readonly) UIImageView *rightImageView;
#pragma mark sigmob 4.1.0 废弃

- (instancetype)initWithFrame:(CGRect)frame;

/**
 每次获取物料信息后需要刷新调用refreshData:方法
 */
- (void)refreshData:(WindNativeAd *)nativeAd;

/**
 在物料加载成功方法里获取相关广告信息赋值后，需调用 setClickableViews:绑定点击的View
 */
- (void)setClickableViews:(NSArray<UIView *> *)clickableViews;

#pragma mark sigmob 4.1.0 废弃
- (void)setPlaceholderImage:(UIImage *)placeholderImage;
#pragma mark sigmob 4.1.0 废弃
/**
 * 绑定展示的图片视图
 *
 * (需要在refreshData方法之后绑定，否则数据无法渲染)
 *
 * @param imageViews     进行渲染的 imageView
 * @param placeholder     图片加载过程中的占位图
 */
- (void)bindImageViews:(NSArray<UIImageView *> *)imageViews placeholder:(UIImage *)placeholder;

/**
 注销数据对象，在 tableView、collectionView 等场景需要复用 WindNativeAdView 时，
 需要在合适的时机，例如 cell 的 prepareForReuse 方法内执行 unregisterDataObject 方法，
 将广告对象与 WindNativeAdView 解绑
 */
- (void)unregisterDataObject;


#pragma mark sigmob 4.1.0 废弃
//****************************************************************************************************

/**
 * 视频广告时长，单位 s
 */
- (CGFloat)videoDuration;

/**
 * 视频广告已播放时长，单位 s
 */
- (CGFloat)videoPlayTime;

/**
 播放视频
 */
- (void)play;

/**
 暂停视频，调用 pause 后，需要被暂停的视频广告对象，不会再自动播放，需要调用 play 才能恢复播放。
 */
- (void)pause;

/**
 停止播放
 */
- (void)stop;

/**
 自定义播放按钮

 @param image 自定义播放按钮图片，不设置为默认图
 @param size 自定义播放按钮大小，不设置为默认大小 44 * 44
 */
//- (void)setPlayButtonImage:(UIImage *)image size:(CGSize)size;
#pragma mark sigmob 4.1.0 废弃
@end
typedef UIView <ABUSigmob_WindNativeAdView> WindNativeAdView;


@protocol ABUSigmob_WindNativeAdViewDelegate <NSObject>

@optional
/**
 广告曝光回调

 @param nativeAdView WindNativeAdView 实例
 */
- (void)nativeAdViewWillExpose:(WindNativeAdView *)nativeAdView;


/**
 广告点击回调

 @param nativeAdView WindNativeAdView 实例
 */
- (void)nativeAdViewDidClick:(WindNativeAdView *)nativeAdView;


/**
 广告详情页关闭回调

 @param nativeAdView WindNativeAdView 实例
 */
- (void)nativeAdDetailViewClosed:(WindNativeAdView *)nativeAdView;


/**
 当点击应用下载或者广告调用系统程序打开时调用
 
 @param nativeAdView WindNativeAdView 实例
 */
- (void)nativeAdViewApplicationWillEnterBackground:(WindNativeAdView *)nativeAdView;


/**
 广告详情页面即将展示回调

 @param nativeAdView WindNativeAdView 实例
 */
- (void)nativeAdDetailViewWillPresentScreen:(WindNativeAdView *)nativeAdView;


/**
 视频广告播放状态更改回调

 @param nativeAdView WindNativeAdView 实例
 @param status 视频广告播放状态
 @param userInfo 视频广告信息
 */
//- (void)nativeAdView:(WindNativeAdView *)nativeAdView playerStatusChanged:(WindMediaPlayerStatus)status userInfo:(NSDictionary *)userInfo;


/**
 点击dislike回调
 开发者需要在这个回调中移除视图，否则，会出现用户点击叉无效的情况
 
 @param filterWords : 选择不喜欢的原因
 */
- (void)nativeAdView:(WindNativeAdView *)nativeAdView dislikeWithReason:(NSArray<WindDislikeWords *> *)filterWords;
@end

@protocol ABUSigmob_WindNativeAdsManager;

typedef NSObject<ABUSigmob_WindNativeAdsManager> WindNativeAdsManager;

@protocol ABUSigmob_WindNativeAdsManagerDelegate <NSObject>
@optional
- (void)nativeAdsManagerSuccessToLoad:(WindNativeAdsManager *)adsManager;

- (void)nativeAdsManagerSuccessToLoad:(WindNativeAdsManager *)adsManager nativeAds:(NSArray<WindNativeAd *> *)nativeAdDataArray;// v3600

- (void)nativeAdsManager:(WindNativeAdsManager *)adsManager didFailWithError:(NSError *_Nullable)error;

@end

@protocol ABUSigmob_WindNativeAdsManager <NSObject>

@property (nonatomic, weak, nullable) id<ABUSigmob_WindNativeAdsManagerDelegate> delegate;

@property (nonatomic, strong, readonly) NSString *placementId;

@property (nonatomic, strong) NSDictionary *extra;// v3600

- (instancetype)initWithRequest:(WindAdRequest *)request;
/**
 It is recommended to request no more than 3 ads.
 */
- (void)loadAdDataWithCount:(NSInteger)count;

/**
*  Called when load the ad
*
*  @param bitToken      - the token from bid request within Sigmob Ad Server
*
*  @param count         - It is recommended to request no more than 3 ads.
*/
- (void)loadAdDataWithBitToken:(NSString *)bitToken
                       adCount:(NSInteger)count;// v3600

/**
 Get all ads when call methord: nativeAdsManagerSuccessToLoad
 */
- (NSArray <WindNativeAd *>*)getAllNativeAds;
@end


NS_ASSUME_NONNULL_END
