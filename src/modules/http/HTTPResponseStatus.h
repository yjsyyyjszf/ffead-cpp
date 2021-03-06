/*
	Copyright 2009-2012, Sumeet Chhetri

    Licensed under the Apache License, Version 2.0 (const the& "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/
/*
 * HTTPResponseStatus.h
 *
 *  Created on: 25-Jan-2013
 *      Author: sumeetc
 */

#ifndef HTTPRESPONSESTATUS_H_
#define HTTPRESPONSESTATUS_H_
#include "string"
#include "map"
#include "CastUtil.h"

struct cicomp {
    bool operator() (const std::string& lhs, const std::string& rhs) const {
        return strcasecmp(lhs.c_str(), rhs.c_str()) < 0;
    }
};

class HTTPResponseStatus {
	HTTPResponseStatus(const int&, const std::string&);
	int code;
	std::string scode;
	std::string msg;
	static std::map<int, HTTPResponseStatus> statuses;
	static std::map<std::string, HTTPResponseStatus> sstatuses;
public:
	static void init();
	HTTPResponseStatus();
	HTTPResponseStatus(const HTTPResponseStatus& status) ;
	HTTPResponseStatus(const HTTPResponseStatus& status, const std::string& msg);
	virtual ~HTTPResponseStatus();
	int getCode() const;
	std::string getSCode() const;
	std::string getMsg() const;
	static const HTTPResponseStatus& getStatusByCode(const int& code);
	static const HTTPResponseStatus& getStatusByCode(const std::string& code);

	static HTTPResponseStatus Continue;
	static HTTPResponseStatus Switching;
	static HTTPResponseStatus Ok;
	static HTTPResponseStatus Created;
	static HTTPResponseStatus Accepted;
	static HTTPResponseStatus NonAuthInfo;
	static HTTPResponseStatus NoContent;
	static HTTPResponseStatus ResetContent;
	static HTTPResponseStatus PartialContent;
	static HTTPResponseStatus ObjectMoved;
	static HTTPResponseStatus MovedPermanently;
	static HTTPResponseStatus NotModified;
	static HTTPResponseStatus TempRedirect;
	static HTTPResponseStatus BadRequest;
	static HTTPResponseStatus AccessDenied;
	static HTTPResponseStatus Unauthorized;
	static HTTPResponseStatus Forbidden;
	static HTTPResponseStatus NotFound;
	static HTTPResponseStatus InvalidMethod;
	static HTTPResponseStatus InvalidMime;
	static HTTPResponseStatus ProxyAuthRequired;
	static HTTPResponseStatus PreconditionFailed;
	static HTTPResponseStatus ReqEntityLarge;
	static HTTPResponseStatus ReqUrlLarge;
	static HTTPResponseStatus UnsupportedMedia;
	static HTTPResponseStatus InvalidReqRange;
	static HTTPResponseStatus ExecutionFailed;
	static HTTPResponseStatus LockedError;
	static HTTPResponseStatus InternalServerError;
	static HTTPResponseStatus InvalidHeaderConf;
	static HTTPResponseStatus BadGateway;
	static HTTPResponseStatus ServiceUnavailable;
	static HTTPResponseStatus GatewayTimeout;
	static HTTPResponseStatus HttpVersionNotSupported;
};

#endif /* HTTPRESPONSESTATUS_H_ */
