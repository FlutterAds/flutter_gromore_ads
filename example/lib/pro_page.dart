import 'package:flutter/material.dart';

/// Pro 页面
class ProPage extends StatefulWidget {
  const ProPage({Key? key}) : super(key: key);

  @override
  State<ProPage> createState() => _ProPageState();
}

class _ProPageState extends State<ProPage> {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('Pro 付费功能'),
      ),
      body: const Center(
        child: Text('此功能是插件 Pro 付费功能，需要购买插件后才能使用,请联系微信：toponelan 咨询购买并获得技术支持'),
      ),
    );
  }
}
