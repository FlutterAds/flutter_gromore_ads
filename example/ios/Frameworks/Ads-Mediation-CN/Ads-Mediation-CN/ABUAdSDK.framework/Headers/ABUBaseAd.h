//
//  ABUBaseAd.h
//  ABUAdSDK
//
//  Created by Makaiwen on 2021/5/21.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "ABUAdSDKConst.h"
#import "ABURitInfo.h"
#import "ABUAdLoadInfo.h"

NS_ASSUME_NONNULL_BEGIN

/// 基类广告
@interface ABUBaseAd : NSObject

/// 广告位ID
@property (nonatomic, copy, readonly) NSString *rit;

/// 广告是否加载中
@property (nonatomic, assign, readonly) BOOL isLoading;

/// 添加参数
/// @param param 参数值
/// @param key 参数key
- (void)addParam:(id)param withKey:(NSString *)key;

/// 加载广告
- (void)loadAdData;

/// 一次waterfall中各adn代码位加载广告失败原因，建议调用时机：展示广告时/超时时/全部返回报错时；返回nil表示一次加载无代码位加载失败或其加载无响应
- (NSArray<NSDictionary *> *)waterfallFillFailMessages;

/// 同`waterfallFillFailMessages`，返回数据为`ABUAdLoadInfo`类型
- (NSArray<ABUAdLoadInfo *> *)getAdLoadInfoList;

/// 是否已经加载配置
@property (nonatomic, assign, readonly) BOOL hasAdConfig ABU_DEPRECATED_MSG_ATTRIBUTE("接口即将废弃，请使用 '+ [ABUAdSDKManager configDidLoad]' 方法代替");

/// 配置加载成功回调，仅执行一次
- (void)setConfigSuccessCallback:(void(^)(void))callback ABU_DEPRECATED_MSG_ATTRIBUTE("接口即将废弃，请使用 '+ [ABUAdSDKManager addConfigLoadSuccessObserver:withAction:]' 方法代替");

/// 在Bididing结束后是否回调ADN结果，默认NO
@property (nonatomic, assign) BOOL bidNotify;

@end

NS_ASSUME_NONNULL_END
