import 'ad_event.dart';

/// 广告错误事件
class AdErrorEvent extends AdEvent {
  AdErrorEvent({
    required String adId,
    required String action,
    required this.errCode,
    this.errMsg,
  }) : super(adId: adId, action: action);
  // 错误码
  final int errCode;
  // 错误信息
  final String? errMsg;
  // 解析 json 为错误事件对象
  factory AdErrorEvent.fromJson(Map<dynamic, dynamic> json) {
    return AdErrorEvent(
      adId: json['adId'],
      action: json['action'],
      errCode: json['errCode'],
      errMsg: json['errMsg'],
    );
  }
}
