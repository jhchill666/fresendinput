package com.tiltdigital.utils
{
	import flash.external.ExtensionContext;

	public class SendInput
	{
		private var context : ExtensionContext;

		private var isConnected : Boolean;


		/**
		 * Creates an Air 3 Native Extension conduit to the win32 'SendInput' method
		 */
		public function SendInput()
		{
			context = ExtensionContext.createExtensionContext( 'com.tiltdigital.utils.SendInput', '' );
		}


		/**
		 *
		 */
		public function sendChar( char:String ):void
		{
			context.call( 'sendInput', char );
		}
	}
}
