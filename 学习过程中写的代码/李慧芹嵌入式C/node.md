# Linux 系统编程

## IO

### 标准 IO

标准 IO 的好处：

1. 可移植
2. 合并系统调用

stdio: FILE 类型贯穿始终

fopen();
fclose();
fgetc();
fputc();

fgets(*,size,stream); 正常结束
size-1
'\n'


fputs();

fread();
fwrite();

printf();
scanf();

fseek();
ftell();
_FILE_OFFSET_BITS
fseeko();
ftello();

frewind();

fflush();
setvbuf(); 设置缓冲区

getline// TODO：实现自己的 getline 函数和 freeline 函数
getline(), getdelim():
        Since glibc 2.10:
            _POSIX_C_SOURCE >= 200809L
        Before glibc 2.10:
            _GNU_SOURCE

errno: `/usr/include/asm-generic/errno-base.h`

与报错相关的函数：

perror();
strerror();

临时文件：1、如何不冲突    2、及时销毁

tmpnam (x)
tmpfile

### 文件 IO / 系统调用 IO

文件描述符是在文件 IO 中贯穿始终的类型

文件描述符：整型数、数组下标、文件描述符优先使用当前可用范围内最小的那一个
文件 IO 操作相关函数：open,close,read,write,lseek

int open(const char *pathname, int flags);
int open(const char *pathname, int flags, mode_t mode);
最终的权限是 mode & ~umask

r->  O_RDONLY
r+-> O_RDWR
w->  O_WRONLY|O_CREATE|O_TRUNC
w+-> O_RDWR|O_TRUNC|O_CREAT
a ->
a+->
标准 IO vs 文件 IO：
区别：响应速度 & 吞吐量
注意：标准 IO 与文件 IO 不可混用
转换：fileno();标准 IO -> 文件 IO 
     fdopen();文件 IO -> 标准 IO

 strace: 可以追踪系统调用

IO 的效率问题
习题：成倍增加 BUFSIZE

文件共享：多个任务共同操作一个文件或者协调完成任务
面试：写程序删除一个文件的第 10 行。
补充：truncate()/ftruncate().

原子操作：不可分割的操作，
原子：不可分割的最小单位
原子操作的作用：解决竞争和冲突

程序中的重定向：dup(),dup2()

同步：sync,fsync,fdatasync


fcntl();文件描述符所变的魔术，基本上都来自于该函数
ioctl();设备相关的内容


/dev/fd/目录：虚目录，显示的是当前进程的文件描述符信息

## 文件系统

类 ls 的实现、叫 myls

一、目录和文件

1、获取文件属性

stat,fstat,lstat
stat 命令是对 stat 系统调用的封装

2、文件访问权限
    st_mode 是一个 16 位的位图，用于表示文件类型，文件访问权限，及特殊权限位


3、umask
    作用：防止产生权限过松的文件

4、文件权限的更改 / 管理 
    chmod
    fchmod
    


5、粘住位
    t 位
    

6、文件系统：FAT、UFS
    文件系统：文件或数据的存储和管理


7、硬链接，符号链接
8、utime
9、目录的创建于销毁
10、更改当前工作路径
11、分析目录 / 读取目录内容



二、系统数据文件和信息



三、进程环境









































