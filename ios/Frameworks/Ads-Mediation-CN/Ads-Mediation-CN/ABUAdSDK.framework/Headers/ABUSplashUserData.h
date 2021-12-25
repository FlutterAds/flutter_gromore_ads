//
//  ABUNewSplashUserData.h
//  ABUAdSDK
//
//  Created by bytedance on 2021/7/30.
//

#import <Foundation/Foundation.h>
#import "ABUAdSDKConst.h"

NS_ASSUME_NONNULL_BEGIN

/// 开屏广告兜底数据
@interface ABUSplashUserData : NSObject

/// adn的名字，请使用如下值 'pangle','baidu','gdt','ks'，其他值可能导致无法加载广告
@property (nonatomic, copy) NSString *adnName;

// adn类型，参考ABUAdnType枚举类型，如1->pangle,3->gdt,4->baidu,7->ks
@property (nonatomic, assign) ABUAdnType adnType ABU_DEPRECATED_MSG_ATTRIBUTE("参数即将废弃，请使用 'adnName' 代替");

// adn对应代码位
@property (nonatomic, copy) NSString *_Nonnull rit;

// adn对应appID
@property (nonatomic, copy) NSString *_Nonnull appID;

// adn对应appKey, 没有时可不传
@property (nonatomic, copy) NSString *_Nullable appKey;

@end

NS_ASSUME_NONNULL_END
