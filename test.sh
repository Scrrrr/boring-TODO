if ! gcc todo.c -o todo; then
	exit -1;	
fi

echo 'Test1 ./todo show'
./todo show
echo 'Status is' $?
echo ''

echo 'Test2 ./todo bufferoverflooooo'
./todo bufferoverflooooooooooooooooowwww
echo 'Status is' $?
echo ''

echo 'Test3 ./todo add'
./todo add
echo 'Status is' $?
echo ''

echo 'Test3 ./todo add これは最初のタスクです'
./todo add これは最初のタスクです
echo 'Status is' $?
echo ''

echo 'Test4 ./todo add a^100'
./todo add aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
echo 'Status is' $?
echo ''
