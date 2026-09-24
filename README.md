Mini-XPER 信用评分项目
本项目的设计思路来源于近期阅读的一篇发表于Management Science期刊的论文：
Hué, S., Hurlin, C., Pérignon, C., & Saurin, S. (2026).
Measuring the driving forces of predictive performance: Application to credit scoring. Management Science.

该论文主要研究信用评分模型中的数据归因问题，提出了XPER（Explainable Performance）框架，用于分析不同特征对模型预测性能的贡献。
本项目基于 XPER 框架的思想，尝试构建一个初步的计算实验环境，用于探索机器学习信用评分模型中的特征贡献分析以及预测性能归因问题。

## 项目概述
在信用风险建模中，机器学习模型通常依赖大量特征进行预测，但模型整体预测性能究竟由哪些变量驱动仍然是一个重要问题。
Hué et al.(2026)提出了 XPER（Explainable Performance）框架，将模型整体预测性能指标分解为不同特征的贡献，从而识别驱动模型预测能力的关键因素。
参考Hué et al.(2026),我希望尽可能复现文章的核心结果，并构建相应的计算流程，完成作业的同时，深入理解这篇文章。

## 项目内容
`README.md`：项目介绍以及使用说明。
`xper_demo.py`：基于模拟信用评分数据的特征贡献分析示例。

## 使用方法
运行 Python 程序：


python xper_demo.py
