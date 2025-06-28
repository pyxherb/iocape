#ifndef _IOCAPE_SOCKET_H_
#define _IOCAPE_SOCKET_H_

#include "async_res.h"

#include <peff/base/uuid.h>

namespace iocape {
	constexpr static peff::UUID
		ADDRFAM_IPV4 = PEFF_UUID(8b7b8980, 494f, 43a9, ad4b, a1486ea6db08),
		ADDRFAM_IPV6 = PEFF_UUID(29a3b911, 0ea7, 466e, 9369, 211345fbd7c4);

	class Socket {
	public:
		IOCAPE_API virtual ~Socket();
	};
}

#endif
