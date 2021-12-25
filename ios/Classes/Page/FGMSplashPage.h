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
@property (strong,nonatomic) ABUSplashAd *ad;
@property (retain,nonatomic) UIView *bottomView;
@property (assign,nonatomic ) BOOL fullScreenAd;
@end
