for f in test_*_*.cpp; do
	
	echo "Compiling: $f"

	# Compile the code!
	g++ --std=c++11 -Wall -O0 "$f" -o test;

	# Halt if there was a compiler error...
	if [ $? -ne 0 ]
	then
		break
  	fi

  	# Run the test!
	./test

	# Halt if the test failed at runtime...
	if [ $? -ne 0 ]
	then
		break
	fi
done

rm test
