//
//  ABUSplashCardView.h
//  Ads-Mediation-CN
//
//  Created by ByteDance on 2022/5/26.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class ABUSplashCardView;

@protocol ABUSplashCardViewDelegate <NSObject>
@optional

/// 开屏广告Cardview点击事件回调
/// @param splashCardView card view
- (void)splashCardViewAdDidClick:(ABUSplashCardView *_Nonnull)splashCardView;

/// 开屏广告Cardview关闭事件回调
/// @param splashCardView card view
- (void)splashCardViewAdDidClose:(ABUSplashCardView *_Nonnull)splashCardView;

/// 开屏广告Cardview已经打开全屏页面事件回调
/// @param splashCardView card view
- (void)splashCardViewAdDidPresentFullScreenModal:(ABUSplashCardView *_Nonnull)splashCardView;

/// 开屏广告Cardview已经关闭全屏页面事件回调
/// @param splashCardView card view
- (void)splashCardViewAdDidDismissFullScreenModal:(ABUSplashCardView *_Nonnull)splashCardView;

@end

@interface ABUSplashCardView : UIView

@property (nonatomic, weak, nullable) id<ABUSplashCardViewDelegate> delegate;

- (void)showSplashCardInRootVC:(UIViewController *)rootVC;

@end

NS_ASSUME_NONNULL_END
