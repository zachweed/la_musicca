require 'yaml'

class LibrarySerializer
  def initialize(path)
    @library_path = path
    @library_data = File.join(File.dirname(__FILE__), './data/library.yml')
  end

  def commit
    File.open(@library_data, 'w'){|f| f.puts YAML.dump(build_directory_list_and_stats)}
  end

  private

    def build_directory_list_and_stats
      directory_count = 0
      dir_dump = {}
      dirs = Dir.entries(@library_path).each do |d|
        directory_count += 1
        if ['.', '..'].include?(d) || (d =~ /\.\w/)
          directory_count -= 1
        else
          dir_dump["#{directory_count}"] = d
          File.directory?(d)
        end
      end
      dir_dump[:count] = directory_count
      dir_dump
    end
end

LibrarySerializer.new('.').commit
