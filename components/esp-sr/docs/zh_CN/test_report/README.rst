测试方法与测试报告
==================

:link_to_translation:`en:[English]`

为了保证 DUT 的性能，可通过测试确定 DUT 在以下方面的表现：

- 唤醒率
- 识别率
- 误唤醒率
- 唤醒打断率
- 响应时间

测试场景要求
------------

以上测试需在合适的测试房间中进行，测试房间应满足如下要求：

* **房间大小**

    * 面积：不小于 4 m * 3.2 m
    * 高度：不低于 2.3 m

* **房间装饰**

    * 地板需配有地毯，天花板需配备常见声学阻尼材料，墙面应有 1 到 2 面墙上挂有窗帘，防止强反射。
    * 房间混响 (RT60) 3在 [125, 8k] 范围内，要满足 0.2-0.7s 的要求。
    * 不要使用消音室。

* **环境底噪**：必须 < 35 dBA，最好 < 30 dBA

* **温度和湿度要求**：20±10°C，相对湿度为 50%±20%。

* **DUT、外部噪声、人声的放置**：

    * DUT、外部噪声、人声的具体位置和相对位置应根据 DUT 的实际应用场景进行安排。

.. note::
    RT60、环境底噪和 DUT、外部噪声、人声的放置应在所有测试中保持不变。

测试案例设计
------------

在设计测试案例时，建议按照产品的实际应用场景，考虑 **以下部分或全部参数**：

- 不同噪声源
    - 白噪声
    - 人类噪声
    - 音乐
    - 新闻
    - . . . . . .
    - 有必要时还可以增加多噪声源的测试场景。
- 不同噪声分贝
    - < 35 dBA
    - 45 dBA
    - 55 dBA
    - 65 dBA
- 不同人声分贝
    - 54 dBA
    - 59 dBA
    - 64 dBA
- 不同 SNR
    - 9 dBA
    - 4 dBA
    - -1 dBA

乐鑫测试与结果
--------------

在本章节描述的所有测试中，DUT、外部噪声、人声的具体位置和相对位置如下所述。

.. figure:: ../../_static/test_reference_position2.png
    :align: center
    :alt: overview

.. figure:: ../../_static/test_reference_position1.png
    :align: center
    :alt: overview

具体来说，

- DUT 距离地面高度 0.75 米
- 人工嘴（人声源）距离地面高度 1.5 米，距离 DUT 直线水平距离 3 米
- 噪声源在相对人工嘴 45°C 角处，距离地面高度 1.2 米，距离 DUT 直线水平距离 2 米
- 声压计位于 DUT 正上方 0.75 米

唤醒率测试
~~~~~~~~~~

**唤醒率**：指当设备处于待唤醒状态时被唤醒成功的概率。

**乐鑫唤醒率测试和结果**

.. list-table::
    :widths: 10 25 15 15 20 15
    :header-rows: 1

    * - 测试案例
      - 噪声类型
      - 噪声分贝
      - 人声分贝
      - SNR
      - 唤醒率
    * - 1
      - /
      - /
      - 59 dBA
      - /
      - 99%
    * - 2
      - 白噪声
      - 55 dBA
      - 59 dBA
      - ≥4 dBA
      - 99%
    * - 3
      - 人声噪声
      - 55 dBA
      - 59 dBA
      - ≥4 dBA
      - 99%

语音识别率测试
~~~~~~~~~~~~~~

**语音识别率**：指当设备处于识别状态时，成功识别词表里包含的命令词的概率。

**乐鑫语音识别率测试和结果**

.. list-table::
    :widths: 10 25 15 15 20 15
    :header-rows: 1

    * - 测试案例
      - 噪声类型
      - 噪声分贝
      - 人声分贝
      - SNR
      - 语音识别率
    * - 1
      - /
      - /
      - 59 dBA
      - /
      - 91.5%
    * - 2
      - 白噪声
      - 55 dBA
      - 59 dBA
      - ≥4 dBA
      - 78.25%
    * - 3
      - 人声噪声
      - 55 dBA
      - 59 dBA
      - ≥4 dBA
      - 82.77%

误唤醒率测试
~~~~~~~~~~~~

**误唤醒率**：指设备在产品定义的应用场景下被非唤醒词成功唤醒的概率。

**乐鑫误唤醒率测试和结果**

.. list-table::
    :widths: 20 20 20 20 20
    :header-rows: 1

    * - 测试案例
      - 噪声类型
      - 噪声分贝
      - 测试时长
      - 误唤醒次数
    * - 1
      - 音乐
      - 55 dBA
      - 12 小时
      - 1 次
    * - 2
      - 新闻
      - 55 dBA
      - 12 小时
      - 1 次

唤醒打断率测试
~~~~~~~~~~~~~~

**唤醒打断率**：唤醒打断率是指设备有自噪时，即有 TTS3 播报或播放音频时，被唤醒成功的概率。对于有 AEC 功能的产品需要进行该测试。

**乐鑫唤醒打断率测试和结果**

.. list-table::
    :widths: 15 15 15 20 15 15
    :header-rows: 1

    * - 测试案例
      - 噪声类型
      - 噪声 / 人声分贝
      - SNR
      - 唤醒率
      - 语音识别率
    * - 1
      - 音乐
      - 69 dBA / 59 dBA
      - ≥10 dBA
      - 100%
      - 96%
    * - 2
      - TTS
      - 69 dBA / 59 dBA
      - ≥10 dBA
      - 100%
      - 96%

响应时间测试
~~~~~~~~~~~~

**响应时间**：代表 DUT 响应语音命令的时间，具体测量为语音指令与播报之间的时间间隔（见下图）。

.. figure:: ../../_static/test_response_time.png
    :align: center
    :alt: overview

**乐鑫响应时间测试和结果**

.. list-table::
    :widths: 25 25 25 25
    :header-rows: 1


    * - 测试案例
      - 噪声 / 人声分贝
      - SNR
      - 响应时间
    * - 1
      - NA / 59 dBA
      - /
      - < 500 ms