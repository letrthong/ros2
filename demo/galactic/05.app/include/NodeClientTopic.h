
class NodeClientTopic {
public:
	NodeClient(NodeClientCallBack nodeClientCallBack);

	void receiveTopicFromINS();
private: 
	NodeClientCallBack nodeClientCallBack_;
};
