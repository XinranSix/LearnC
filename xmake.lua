add_rules("mode.debug", "mode.release")

add_includedirs("include")

add_requires("tbox") -- c 语言的一个工具库

includes("c_test")
includes("学习过程中写的代码")
includes("代码片段")

-- for _, filepath in ipairs(os.files("./**.cpp")) do
-- target(path.basename(filepath))
--     add_files(filepath)
--     set_rundir(path.directory(filepath))
--     add_packages("fmt", "boost", "openssl", "jsoncpp", "ftxui", "gtest", "eigen", "ncurses")
-- end
