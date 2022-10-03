import 'dart:io';

/// 广告配置信息
class AdsConfig {
  /// 获取 Logo 资源名称
  static String get logo {
    if (Platform.isAndroid) {
      return 'flutterads_logo';
    } else {
      return 'LaunchImage';
    }
  }

  /// 获取 Logo 资源名称 2
  static String get logo2 {
    if (Platform.isAndroid) {
      return 'flutterads_logo2';
    } else {
      return 'LaunchImage2';
    }
  }

  /// 获取 App id
  static String get appId {
    if (Platform.isIOS) {
      return '5000546';
    }
    return '5001121';
  }

  /// 获取 App Config
  static String get config {
    if (Platform.isIOS) {
      return 'ios_config_5209496';
    }
    return 'android_config_5216573.json';
  }

  /// 获取开屏广告位id
  static String get splashId {
    if (Platform.isIOS) {
      return '887383142';
    }
    return '887382967';
  }

  /// 获取插屏广告位id
  static String get interstitialId {
    if (Platform.isIOS) {
      return '945494755';
    }
    return '945493679';
  }

  /// 获取插屏全屏广告位id
  static String get interstitialFullId {
    if (Platform.isIOS) {
      return '946961656';
    }
    return '946276599';
  }

  /// 获取全屏视频广告位id(纵向)
  static String get fullVideoVerticalId {
    if (Platform.isIOS) {
      return '900546831';
    }
    return '945493676';
  }

  /// 获取全屏视频广告位id(横向)
  static String get fullVideoHorizontalId {
    if (Platform.isIOS) {
      return '945494751';
    }
    return '945493675';
  }

  /// 获取激励视频广告位id
  static String get rewardVideoId => '946584890';

  /// 获取 Banner 广告位id
  static String get bannerId => '946651948';

  /// 获取 Banner 广告位id 01
  static String get bannerId01 => '946651966';

  /// 获取 Banner 广告位id 02
  static String get bannerId02 => '946651971';

  /// 获取 Feed 信息流列表
  static List<String> get feedIdList =>
      [feedId01, feedId02, feedId03, feedId04, feedId05];

  /// 获取 Feed 信息流广告位id(左右图文 2.4)
  static String get feedId01 => '947186177';

  /// 获取 Feed 信息流广告位id(上下文图0.9)
  static String get feedId02 => '947186943';

  /// 获取 Feed 信息流广告位id(三图2)
  static String get feedId03 => '947186944';

  /// 获取 Feed 信息流广告位id(文字悬浮1)
  static String get feedId04 => '947186945';

  /// 获取 Feed 信息流广告位id(竖版0.5)
  static String get feedId05 => '947186946';
}
