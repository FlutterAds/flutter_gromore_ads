//
//  ABUSigmobNewSplashBridge.h
//  ABUAdSigmobAdapter
//
//  Created by heyinyin on 2022/7/12.
//

#import <Foundation/Foundation.h>
# if __has_include(<ABUAdSDK/ABUAdSDK.h>)
#import <ABUAdSDK/ABUAdSDK.h>
#else
#import <Ads-Mediation-CN/ABUAdSDK.h>
#endif
#import "ABUSigmobSplashAdapter.h"

NS_ASSUME_NONNULL_BEGIN

@interface ABUSigmobNewSplashReplacer : NSObject
@property (nonatomic, weak) ABUSigmobSplashAdapter *adapter;
@end

NS_ASSUME_NONNULL_END
