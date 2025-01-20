import 'package:flutter/material.dart';

import 'pro_page.dart';

void main() {
  // 绑定引擎
  WidgetsFlutterBinding.ensureInitialized();
  // 启动
  runApp(const MyApp());
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
