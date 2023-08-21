for _, filepath in ipairs(os.files("./**.c")) do
target('杂七杂八的代码_' ..path.basename(filepath))
    add_files(filepath)
    set_rundir(path.directory(filepath))
    add_packages("gtest", "fmt")
end
