import 'package:plugin_platform_interface/plugin_platform_interface.dart';
import 'flutter_gromore_ads_method_channel.dart';

abstract class FlutterGromoreAdsPlatform extends PlatformInterface {
  FlutterGromoreAdsPlatform() : super(token: _token);

  static final Object _token = Object();

  static FlutterGromoreAdsPlatform _instance = MethodChannelFlutterGromoreAds();

  static FlutterGromoreAdsPlatform get instance => _instance;

  static set instance(FlutterGromoreAdsPlatform instance) {
    PlatformInterface.verifyToken(instance, _token);
    _instance = instance;
  }

  Future<bool> requestIDFA() {
    throw UnimplementedError('requestIDFA() has not been implemented.');
  }

  Future<bool> requestPermissionIfNecessary() {
    throw UnimplementedError(
        'requestPermissionIfNecessary() has not been implemented.');
  }

  Future<bool> initAd(String appId,
      {String? config, int limitPersonalAds = 0}) {
    throw UnimplementedError('initAd() has not been implemented.');
  }

  Future<bool> showSplashAd(String posId,
      {String? logo, double timeout = 3.5}) {
    throw UnimplementedError('showSplashAd() has not been implemented.');
  }

  Future<bool> showInterstitialAd(String posId) {
    throw UnimplementedError('showInterstitialAd() has not been implemented.');
  }

  Stream<dynamic> getEventStream() {
    throw UnimplementedError('getEventStream() has not been implemented.');
  }
}
