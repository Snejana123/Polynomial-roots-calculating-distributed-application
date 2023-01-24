# Polynomial-roots-calculating-distributed-application
Distributed application, including client and server part interacting through network exchange messages

Class specifications.
Communicator
1) Class TCommParams - connection parameters
Attributes:

• - rHost: QHostAddress - client host address

• -rPort: quint16 - client port

• -sHost: QHostAddress - server host address

• -pPort: quint16 - server port

2) Class TCommunicator - client side communicator

Attributes:

• -ready: bool – connection flag

• - params: TCommParams – parameters for setting up a connection

• + TCommunicator(TCommParams&,QObject *parent = nullptr) -
class constructor that accepts parameter values for
connection setup

• + bool isReady() - return connection status

• + ~TCommunicator() – class destructor

• void received() – message receive signal

• + void send(QByteArray) – message send slot

• + void connectedWithHost() - connection establishment slot

• + void disconnectedFromHost() – disconnection slot

• + void error(QAbstractSocket::SocketError error) – mistake message slot

• - void receive() - message receiving slot

3) TServerTcp class - server-side communicator

Attributes:

• -ready: bool – connection flag

• +TServerTcp(TCommParamsServer&, QObject*) – constructor class

• + bool isReady() - return connection status

• void recieved(QTcpSocket *, QByteArray) – messages receiving signal

• -void send(QTcpSocket *, QByteArray) – message send slot

• -void receive(QTcpSocket *) – message receiving slot

• -void newConnection() – connection establishment slot

Server:

4) TPolinom class - storage of a polynomial, roots searching, etc.

Attributes:

• - printMode: EPrintMode – polynomial output model selection

• - a: number – coefficient at x^2

• - b: number – coefficient at x

• - c: number – free member

• + roots[3]: double – an array to store the number of roots and their values

• + TPolinom(number, number, number) – class constructor, taking the values of the coefficients

• + ostream& operator<< (ostream&, TPolinom&) – friendly function that overrides the << output stream operator for TPolinom type parameters

• value(number): number – calculation of the polynomial value with given x variable value

• setPrintMode(EPrintMode) – method for setting the polynomial output model

• getRoots() – method for calculating polynomial roots, values are stored in
roots[3]

• printRoots() - method for printing roots on the screen

5) TRational - a class for implementing an application on a rational numbers set

Attributes:

• - SEPARATOR: QChar - separator for parsing messages

• -a:int – numerator

• -b:int- denominator

• +TRational() – class constructor

• + TRational(const int&) - class constructor that accepts denominator value in integer form, numerator = 1.

• + TRational(const QByteArray&) - class constructor, accepting QByte array

• TRational operator* (TRational) – implementation of rational numbers multiplication operation

• TRational operator* (int) – implementation of the integer numbers multiplication operation

• TRational operator+ (TRational) - implementation of the rational numbers addition operation

• TRational operator- (TRational) - implementation of the subtraction rational numbers operation

• TRational operator- () – implementation of the rational number sign changing unary operation

• TRational operator/ (TRational) - implementation of the rational numbers division operation

• void operator= (TRational) – implementation of assignment operation

• void operator() (int, int) – implementation of assignment operator with 2
integer parameters

• friend TRational sqrt(TRational) – square root extraction implementation

• bool operator== (TRational) – rational numbers equality operation implementation

• bool operator== (int) – integer numbers equality operation implementation

• bool operator!= (TRational) - rational numbers inequality operation implementation

• bool operator!= (int) - integer numbers inequality operation implementation

• bool operator> (TRational) - rational numbers comparison operation '>' implementation 

• bool operator> (int) - integer numbers comparison operation > implementation

• bool operator< (TRational) - rational numbers comparison operation < implementation

• bool operator< (int) - integer numbers comparison operation < implementation

• void gcd () – rational number reduction to an irreducible form

• double doubleConvert() – implementation of TRational type conversion to
double

• +friend ostream& operator<< (ostream&,TRational) - friendly function that overrides the output stream operator << for TRational parameters

• + friend QString& operator<<(QString&, TRational) - friendly function wich override QString operator >> for TRational parameters

• + friend QByteArray& operator>>(QByteArray& , TRational&) – friendly function wich override QByteArray operator >> for TRational parameters

• +static QChar getSeparator() - returns the separator

• +void setSeparator(QChar) – separator setting

• +friend istream& operator>> (istream&,TRational&) - friendly function that overrides the operator >> of the input stream for TRational parameters

• +friend TRational sqrt(TRational) - friendly function redefining the square root extracting function of rational number

• + operator QString() – operator for type conversion

6) TApplication - application server side implementing class

Attributes:

• -comm: TCommunicator* - communicator parameters

• + TApplication(int, char**) – class constructor

• + void recieve(QTcpSocket*, QByteArray) – slot for receiving a message

Client:
7) TInterface - a class for implementing the graphical interface of the application

Attributes:

• -*name_a, *delimeter_a: QLAbel - labels for coefficient a

• -*a_num, *a_den: QLineEdit - input fields for coefficient a

• -*name_b, *delimeter_b: QLabel - labels for coefficient b

• -*b_num, *b_den: QLineEdit - input fields for coefficient b

• -*name_c, *delimeter_c: QLabel - labels for coefficient c

• -*c_num, *c_den: QLineEdit - coefficient c input fields

• -*name_x, *delimeter_x: QLabel - labels for parameter x

• - *x_num, *x_den: QLineEdit - parameter x input fields

• - *value_btn, *root_btn, *print_classic_btn, *print_canonical_btn:
QPushButton - buttons for launching the execution of class methods
TPolinom

• - *output: QLabel – label for displaying program results

• + TInterface(QWidget *parent = nullptr) – class constructor

• +~TInterface() – class destructor

• +void answer(QString) – response output slot

• +void formRequest() – slot for generating a request to the server

• void request(QString) – request signal

8) TApplication - a class for implementing an application on the client side
9) 
Attributes:

• - comm: TCommunicator* - communicator parameters

• -interface: TInterface* - application interface

• +TApplication(int, char**) – class constructor

• + void fromCommunicator(QByteArray) - slot for receiving a message from a communicator

• + void toCommunicator(QString) – slot for sending message to communicator

Class diagrams

Client part

![Client class](https://user-images.githubusercontent.com/103432419/214328561-12b110c6-fbc1-46bd-96b8-0507640c1480.jpg)

Server part

![Server class](https://user-images.githubusercontent.com/103432419/214328606-59c1edb8-7ff2-469e-89c4-c1ae6876e97c.jpg)

Interface

![изображение](https://user-images.githubusercontent.com/103432419/214334325-556b6a54-4b28-4edb-aa47-851fda56493f.png)




