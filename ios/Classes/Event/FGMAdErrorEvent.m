//
//  FGMAdErrorEvent.m
//  flutter_gromore_ads
//
//  Created by zero on 2021/12/11.
//

#import "FGMAdErrorEvent.h"

@implementation FGMAdErrorEvent
- (id)initWithAdId:(NSString *)adId errCode:(NSNumber *)errCode errMsg:(NSString *)errMsg{
    self.adId=adId;
    self.action=onAdError;
    self.errCode=errCode;
    self.errMsg=errMsg;
    return self;
}

- (id)initWithAdId:(NSString *)adId error:(NSError *)error{
    return [self initWithAdId:adId errCode:[NSNumber numberWithInteger:error.code] errMsg:error.domain];
}

- (NSDictionary *)toMap{
    NSMutableDictionary *errData=[[NSMutableDictionary alloc] initWithDictionary:[super toMap]];
    [errData setObject:self.errCode forKey:@"errCode"];
    [errData setObject:self.errMsg forKey:@"errMsg"];
    return errData;
}
@end
