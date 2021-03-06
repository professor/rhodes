package com.rho;

import com.rho.db.PerstLiteAdapter;
import com.xruby.runtime.lang.*;
import com.xruby.runtime.builtin.*;

//@RubyLevelClass(name="StringScanner")
public class StringScanner extends RubyBasic {

	RubyString str;
	
	StringScanner(RubyClass c) {
		super(c);
	}

    //@RubyAllocMethod
    public static StringScanner alloc(RubyValue receiver) {
        return new StringScanner(RubyRuntime.StringScannerClass);
    }
	
    //@RubyLevelMethod(name="initialize")
    public StringScanner initialize(RubyValue v) {
    	str = v.toRubyString();
        return this;
    }
	
	public static void initMethods( RubyClass klass){
		klass.defineMethod( "initialize", new RubyOneArgMethod(){ 
			protected RubyValue run(RubyValue receiver, RubyValue arg, RubyBlock block ){
				return ((StringScanner)receiver).initialize(arg);}
		});
		klass.defineAllocMethod(new RubyNoArgMethod(){
			protected RubyValue run(RubyValue receiver, RubyBlock block )	{
				return StringScanner.alloc(receiver);}
		});
		
	}
    
}
