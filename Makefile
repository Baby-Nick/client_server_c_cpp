COMPILER=g++
SOURCE_FOLDER=src
BUILD_FOLDER=build

server: $(SOURCE_FOLDER)/server.cpp
	mkdir -p $(BUILD_FOLDER)
	$(COMPILER) -o $(BUILD_FOLDER)/server $(SOURCE_FOLDER)/server.cpp

client: $(SOURCE_FOLDER)/client.cpp
	mkdir -p $(BUILD_FOLDER)
	$(COMPILER) -o $(BUILD_FOLDER)/client $(SOURCE_FOLDER)/client.cpp

run_server:
	./$(BUILD_FOLDER)/server

run_client:
	./$(BUILD_FOLDER)/client

clean:
	rm -r $(BUILD_FOLDER)
