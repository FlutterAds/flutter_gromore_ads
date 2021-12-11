//
//  FGMBasePage.h
//  flutter_gromore_ads
//
//  Created by zero on 2021/12/11.
//

#import <Foundation/Foundation.h>
#import <Flutter/Flutter.h>
# if __has_include(<ABUAdSDK/ABUAdSDK.h>)
#import <ABUAdSDK/ABUAdSDK.h>
#else
#import <Ads-Mediation-CN/ABUAdSDK.h>
#endif
// 基础广告页面
@interface FGMBasePage : NSObject
// 广告位 id
@property (strong,nonatomic) NSString *posId;
// 窗口
@property (strong,nonatomic) UIWindow *mainWin;
// 跟控制器
@property (strong,nonatomic) UIViewController *rootController;
//显示广告
- (void) showAd:(FlutterMethodCall*) call eventSink:(FlutterEventSink) events;
// 加载广告
- (void) loadAd:(FlutterMethodCall*) call;
@end
