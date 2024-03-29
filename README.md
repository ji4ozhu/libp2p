## NAT穿透技术现状

| 级别 | 穿透率  | 理论     | 实现                                                                          |
|------|---------|----------|-------------------------------------------------------------------------------|
| 初级 | 30%~35% | STUN     | STUN标准实现                                                                  |
| 中级 | 50%~75% | STUN     | STUN标准实现，可能拥有防火墙穿透技术，或者做了一些其他优化                    |
| 高级 | 90%~95% | 自研     | 利用Linux内核实现上的特性，重新定义了设备类型，防火墙穿透技术，多线路穿透技术 |

## 基于STUN理论的NAT穿透成功率 

| NAT类型          | 终端占比 | 穿透率 |
|------------------|----------|--------|
| 全锥型           | 5%       | 100%   |
| 限制锥型         | 7%       | 100%   |
| 端口限制锥型     | 58%      | 70%    |
| 对称型           | 30%      | 12%    |

* 各类型终端占比数据来自六万个光纤网络终端的统计

* 理论穿透率 = 5% x 100% + 7% x 100% + 58% x 70% + 30% x 12% = 56.20%

* 实际穿透率 ≈ 30% ( NAT防火墙阻挡 )

## 基于Linux内核特性的NAT设备分类

| Linux Based NAT Classify | 特征                                                           |
|--------------------------|----------------------------------------------------------------|
| 主机端口                 | 在端口未占用的情况下，优先映射内网主机的主机端口               |
| 固定端口                 | 内网主机使用相同主机端口，请求不同的外网主机，映射的端口号相同 |
| 对称端口                 | 内网主机使用相同主机端口，请求不同的外网主机，映射的端口号不同 |

## 基于Linux内核特性的NAT穿透成功率

| NAT类型  | 终端占比 | 穿透率 |
|----------|----------|--------|
| 主机端口 | 75%      | 98%    |
| 固定端口 | 23%      | 98%    |
| 对称端口 | 2%       | 0%     |

* 各类型终端占比数据来自六万个光纤网络终端的统计

* 理论穿透率 = 75% x 98% + 23% x 98% + 2% x 0% = 96.04%

* 实际穿透率 ≈ 96% ( NAT防火墙穿透 )
