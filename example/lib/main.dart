import 'package:flutter/material.dart';
import 'package:flutter_gromore_ads/flutter_gromore_ads.dart';

import 'pro_page.dart';

void main() {
  // 绑定引擎
  WidgetsFlutterBinding.ensureInitialized();
  // 启动
  runApp(const MyApp());

  // 初始化
  init();
}

class MyApp extends StatefulWidget {
  const MyApp({Key? key}) : super(key: key);

  @override
  State<MyApp> createState() => _MyAppState();
}

class _MyAppState extends State<MyApp> {
  @override
  Widget build(BuildContext context) {
    return const MaterialApp(
      home: ProPage(),
    );
  }
}

/// 初始化
Future<void> init() async {
  // 设置监听
  FlutterGromoreAds.onEventListener((event) {
    print('🎉🎉🎉 FlutterAds ==> $event');
  });

  // 初始化
  await FlutterGromoreAds.initAd(
    '1234567890',
    config: 'config.json',
  );

  // 展示开屏广告
  await FlutterGromoreAds.showSplashAd('1234567890');
}
