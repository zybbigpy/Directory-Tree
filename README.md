# 简易目录树

## 实现方法

用兄弟-孩子表示法描绘一个目录树, 同时对于每个节点加入`深度`信息, 即距离根目录的深度。

1. 使用该方法可以方便的实现Linux 下的目录树。
2. 使用该方法可以方便的实现Linux 下的进程树。 (NJU-OS-LAB-01)

---

## 运行测试

### 内置简单测试

`treePrint.c` 文件提供了相关的结点接口，调用打印接口和一个简单测试。使用方法为：

```bash
make && make run
```

### Linux Pstree测试

测试完成！等待后续发布。

---

## 运行结果

![result](https://github.com/zybbigpy/Directory-Tree/blob/master/img/result.PNG)

---

## 参考

1. [控制台打印二叉树的有趣方法](https://stackoverflow.com/questions/801740/c-how-to-draw-a-binary-tree-to-the-console)
2. [竖直打印二叉树](http://tieba.baidu.com/p/2860225921)