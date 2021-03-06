// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include "./gen-cpp/XSMBService.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>
#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using boost::shared_ptr;

using namespace  ::azure::storage::linuxFileClient;

class XSMBServiceHandler : virtual public XSMBServiceIf {
 public:
  XSMBServiceHandler() {
    // Your initialization goes here
  }

  bool CreateDirectory(const std::string& dirPath) {
    // Your implementation goes here
    printf("CreateDirectory\n");
	bool success = false;
	boost::filesystem::path dir(dirPath);
	try {
		if (boost::filesystem::exists(dir)) {
			success = false;
		} else {
			success = boost::filesystem::create_directory(dir);
		}
	} catch (const boost::filesystem::filesystem_error& ex) {
		std::cout << ex.what() << std::endl;
	}
	return success;

  }


  bool DeleteDirectory(const std::string& dirPath, const bool isRecursive) {
    // Your implementation goes here
    printf("DeleteDirectory\n");
	bool success = false;
	boost::filesystem::path dir(dirPath);
	try {
		if (!(!boost::filesystem::is_empty(dir) && !isRecursive)) {
			if (boost::filesystem::exists(dir)) {
				success = boost::filesystem::remove_all(dir);
			} else {
				success = true;
			}
		} else {
			std::cout << "Error: " << dirPath << " is not empty while isRecursive is false" << std::endl;
		}
	} catch (const boost::filesystem::filesystem_error& ex) {
		std::cout << ex.what() << std::endl;
	}
	return success;
  }

  bool CreateFile(const std::string& filePath, const int64_t fileSize, const bool noBuffering) {
    // Your implementation goes here
    printf("CreateFile\n");
	bool success = false;
	boost::filesystem::path file(filePath);
	try {
		if (boost::filesystem::exists(file)) {
			success = false;
		} else {
			boost::filesystem::fstream fs;
			fs.open(file, boost::filesystem::fstream::out);
			fs.seekp(fileSize - 1);
			fs.write("", 1);
			fs.close();
			success = true;
		}
	} catch (const boost::filesystem::filesystem_error& ex) {
		std::cout << ex.what() << std::endl;
	}
	return success;
  }

  bool DeleteFile(const std::string& filePath) {
    // Your implementation goes here
    printf("DeleteFile\n");
	bool success = false;
	boost::filesystem::path file(filePath);
	try {
		if (boost::filesystem::exists(file)) {
			success = boost::filesystem::remove(file);
		} else {
			success = true;
		}
	} catch (const boost::filesystem::filesystem_error& ex) {
		std::cout << ex.what() << std::endl;
	}
	return success;
  }

  bool ReadFile(const std::string& filePath, const StreamDataLayout& data, const bool noBuffering, const int8_t fileVersion, const bool useVersionInData, const std::string& keyName) {
    // Your implementation goes here
	/*
    printf("ReadFile\n");
	
	int8_t buf[data.chunks.max_size()];
	try {
		stream
	}
	return true;
	 */
	 return true;
  }

  bool WriteFile(const std::string& filePath, const StreamDataLayout& data, const bool noBuffering, const int8_t fileVersion, const bool useVersionInData, const std::string& keyName) {
    // Your implementation goes here
    printf("WriteFile\n");
	return true;
  }

  bool ListFiles(const std::string& dirPath) {
    printf("ListCloudFiles\n");
	boost::filesystem::path dir(dirPath);
	try {
		std::copy(boost::filesystem::directory_iterator(dir), 
			boost::filesystem::directory_iterator(), 
			std::ostream_iterator<boost::filesystem::directory_entry>(std::cout, "\n"));
	} catch (const boost::filesystem::filesystem_error& ex) {
		std::cout << ex.what() << std::endl;
	}
	return true;
  }

  bool ListCloudFiles(const std::string& dirPath, const bool isRecursive, const std::map<std::string, MatchInformation::type> & files, const std::map<std::string, MatchInformation::type> & dirs) {
    // Your implementation goes here
    printf("ListCloudFiles\n");
	boost::filesystem::path dir(dirPath);
	try {
		std::copy(boost::filesystem::directory_iterator(dir), 
			boost::filesystem::directory_iterator(), 
			std::ostream_iterator<boost::filesystem::directory_entry>(std::cout, "\n"));
	} catch (const boost::filesystem::filesystem_error& ex) {
		std::cout << ex.what() << std::endl;
	}
	return true;
  }

  int64_t GetCloudFileLength(const std::string& filePath) {
    // Your implementation goes here
	boost::filesystem::path file(filePath);
	int64_t fileSize = 0;
	try {
		if (boost::filesystem::exists(file)) {
			if (boost::filesystem::is_regular_file(file)) {
				fileSize = (int64_t)boost::filesystem::file_size(file);
				std::cout << file << ": " << fileSize << "bytes" << std::endl;
			} else if (boost::filesystem::is_directory(file)) {
				std::cout << file << " is a directory" << std::endl;
			} else {
				std::cout << file << " exists, but is neither a file or directory" << std::endl;
			}
		} else {
			std::cout << file << " does not exist" << std::endl;
		}
	} catch (const boost::filesystem::filesystem_error& ex) {
		std::cout << ex.what() << std::endl;
	}
    printf("GetCloudFileLength\n");
	return 0;
  }

  bool SetCloudFileLength(const std::string& filePath, const int64_t fileLength) {
    // Your implementation goes here
    printf("SetCloudFileLength\n");
	bool success = false;
	boost::filesystem::path file(filePath);
	try {
		if (!boost::filesystem::exists(file)) {
			success = false;
			std::cout << file << " does not exist" <<std::endl;
		} else {
			boost::filesystem::resize_file(file, (uintmax_t)fileLength);
			success = true;
		}
	} catch (const boost::filesystem::filesystem_error& ex) {
		std::cout << ex.what() << std::endl;
	}
	return success;
  }

};

int main(int argc, char **argv) {
 	int port = 9090;
  	shared_ptr<XSMBServiceHandler> handler(new XSMBServiceHandler());
 	shared_ptr<TProcessor> processor(new XSMBServiceProcessor(handler));
  	shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  	shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  	shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());
  	XSMBServiceHandler* service = new XSMBServiceHandler();	
	/*
	std::cout << "Creating Directory..." << std::endl;
	service->CreateDirectory("/home/xufyan/testdir/");
	std::cout << "Creating File..." << std::endl;
	service->CreateFile("/home/xufyan/testdir/test.txt", 2016, false);
	service->CreateFile("/home/xufyan/testdir/test1.txt", 2016, false);
	service->CreateFile("/home/xufyan/testdir/test2.txt", 2016, false);
	service->ListFiles("/home/xufyan/testdir/");
	std::cout << "Deleting Files..." << std::endl;
	service->DeleteFile("/home/xufyan/testdir/test.txt");
	service->ListFiles("/home/xufyan/testdir");
	 */
	//service->DeleteDirectory("/home/xufyan/testdir", false);	
	service->GetCloudFileLength("/home/xufyan/testdir/test.txt");
	service->SetCloudFileLength("/home/xufyan/testdir/test.txt", 12);
	service->GetCloudFileLength("/home/xufyan/testdir/test.txt");
  	TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  	server.serve();
  	return 0;
}

