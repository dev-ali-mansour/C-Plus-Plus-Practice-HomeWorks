class EmailService {
};

class LoggingSupport {
};

class CachingSupport {
};

class ThreadSafeSupport {
};

class PureEmailService : public EmailService {
};

class EmailServiceWithLogging : public EmailService, public LoggingSupport {
};

class EmailServiceWithLoggingAndCaching :
        public EmailService, public LoggingSupport, public CachingSupport {
};

class AllInOneEmailService :
        public EmailService, public LoggingSupport, public CachingSupport, public ThreadSafeSupport {
};