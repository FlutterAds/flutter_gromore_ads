//
//  FGMSplashPage.h
//  flutter_gromore_ads
//
//  Created by zero on 2021/12/11.
//

#import <Foundation/Foundation.h>
#import "FGMBasePage.h"

// 开屏广告
@interface FGMSplashPage :FGMBasePage
// 开屏
@property (strong,nonatomic) BUSplashAd *ad;
@property (retain,nonatomic) UIView *bottomView;
@property (assign,nonatomic ) BOOL fullScreenAd;
// 广告是否展示中
@property (assign,nonatomic ) BOOL isDisplay;
@end
