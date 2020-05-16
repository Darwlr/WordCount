1、创建空目录并初始化为git仓库
git init test

2、git 常用指令
查看当前状态： git status
将文件添加到缓存区： git add 文件名
	语法1：git add 文件名
	语法2：git add 文件名1 文件名2
	语法3：git add .	【将当前目录全部存到缓存区】
提交至版本库：git commit -m "描述"

3、版本回退
步骤：
 - 查看版本，确定需要回到的时刻点
	git log	【显示日志】
	git log --pretty=oneline	【一行是一个时刻】
 - 回退操作
	git reset --hard 提交编号
【注意】如果回到过去之后，又想回到之前最新的版本的时候，则需要指令去查看历史操作，
以得到最新的commit id。
	git reflog
	git reset --hard commit id

[小结]
 a. 要想回到过去，必须先得到commit id,然后通过 git reset --hard commit id 进行回退
 b. 要想回到未来，需要使用 git reflog 进行历史操作查看，得到最新的commit id
 c. 在写回退指令的时候commit id 可以不用写全，git自动识别，但是也不能写得太少，至少需要写前4位字符
 
4、远程仓库

5、两种常规使用方式
 - 基于http协议
   a. git clone https://xxxx
   b. 在仓库上做对应的操作（提交暂存区、提交本地仓库、提交线上仓库、拉取线上仓库）
		git add filename
		git commit -m "描述"
		git push  【提交到远程仓库】
			
	[注意]:在首次往线上仓库提交内容时出现了403的致命错误，原因是不是任何人都可以往线上仓库
	提交内容，必须先鉴权。
	 【需要修改 ".git/config" 的文件内容】
	 ##将
	 [remote "origin"]
		//http
		url = https://用户名:密码@github.com/用户名/仓库名.git
		
		//ssh
		url = git@github.com:Darwlr/gitskills.git
		
	c. 拉取线上仓库到本地
		git pull
		**注意**：
		 - 每天工作的第一件事就是先 git pull 拉取线上最新版本
		 - 每天下班要做的就是 git push，将本地代码提交到仓库
	
	
 - 基于ssh协议
	a. 生成客户端公私钥文件(安装openssh)
		ssh-keygen -t rsa -C "注册邮箱"
	b. 将id_isa.pub的内容添加到github的ssh公钥中
	
	
6、分支管理
查看分支：git branch
创建分支：git branch 分支名
切换分支：git checkout 分支名
创建并切换到分支：git checkout -b 分支名
删除分支：git branch -d 分支名
	[注意]在删除分支时，要先退出要删除的分支，然后才能删除
合并分支：git merge 被合并的分支名


7、冲突的产生与解决
- 冲突的产生：在本地和远程仓库上均作了修改
- 解决冲突
 a. git pull
	会将冲突的内容写到冲突文件中
 b. 打开冲突文件，解决冲突
	将冲突文件里面的内容进行手动调整，保留需要的，不需要的进行删除
 c. 重新提交
























	